#include "webpage.h"
#include <QAuthenticator>

WebPage::WebPage(QObject *parent)
    : QWebEnginePage(parent)
{
    connect(this, SIGNAL(authenticationRequired(const QUrl &, QAuthenticator*)),
        SLOT(authenticationRequired(const QUrl &, QAuthenticator*)));
    connect(this, SIGNAL(proxyAuthenticationRequired(const QUrl &, QAuthenticator *, const QString &)),
        SLOT(proxyAuthenticationRequired(const QUrl &, QAuthenticator *, const QString &)));
}

void WebPage::updateAuth(QAuthenticator *auth)
{
    if (auth) {
        QString user, pass;
        auth->setUser(user);
        auth->setPassword(pass);
    }
}

bool WebPage::acceptNavigationRequest(const QUrl &url, NavigationType type, bool isMainFrame)
{
    if (isMainFrame) {
        if (NavigationTypeLinkClicked == type) {
            emit sigLoadUrl(url);
            return false;
        }
    }
    return true;
}

void WebPage::javaScriptConsoleMessage(JavaScriptConsoleMessageLevel level, const QString &message, int lineNumber, const QString &sourceID)
{
    QString levelStr = (level == 0 ? "INFO" : (level == 1 ? "WARN" : "ERROR"));
    QString htmlName = sourceID;
    int findPos = sourceID.lastIndexOf("/");
    if (findPos >= 0) {
        htmlName = sourceID.mid(findPos + 1);
    }
    QString webLog = QString("[WEBLOG level:%1,line:%2,name:%3] %4").arg(levelStr).arg(lineNumber).arg(htmlName).arg(message);
    qDebug() << webLog;
}

QWebEnginePage *WebPage::createWindow(WebWindowType type)
{
    emit sigCreateWindow(type);
    return nullptr;
}

void WebPage::authenticationRequired(const QUrl &requestUrl, QAuthenticator *auth)
{
    qDebug() << "authenticationRequired, url:" << requestUrl.toString();
    updateAuth(auth);
}

void WebPage::proxyAuthenticationRequired(const QUrl &requestUrl, QAuthenticator *auth, const QString &proxyHost)
{
    qDebug() << "proxyAuthenticationRequired, url:" << requestUrl.toString() << ", proxyHost:" << proxyHost;
    updateAuth(auth);
}
