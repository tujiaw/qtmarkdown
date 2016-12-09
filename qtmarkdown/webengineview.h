#ifndef WEBENGINEVIEW_H
#define WEBENGINEVIEW_H

#include <QWebEngineView>

class WebChannel;
class WebPage;
class WebEngineView : public QWebEngineView
{
public:
    WebEngineView(QWidget *parent);

private slots:
    void slotWebRequest(const QString &commandName, const QString &jsonParams);
    void slotLoadFinished(bool finished);

private:
    WebChannel *m_channel;
    WebPage *m_page;
};

#endif // WEBENGINEVIEW_H
