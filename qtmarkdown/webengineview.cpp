#include "webengineview.h"
#include "webchannel.h"
#include "webpage.h"

WebEngineView::WebEngineView(QWidget *parent)
    : QWebEngineView(parent)
    , m_channel(new WebChannel(this))
    , m_page(new WebPage(this))
{
    this->setPage(m_page);
    page()->setWebChannel(m_channel->channel());

    connect(m_channel, &WebChannel::sigWebRequest, this, &WebEngineView::slotWebRequest);
    connect(this, &QWebEngineView::loadFinished, this, &WebEngineView::slotLoadFinished);
}

void WebEngineView::slotWebRequest(const QString &commandName, const QString &jsonParams)
{

}

void WebEngineView::slotLoadFinished(bool finished)
{
    qDebug() << "load finished:" << finished;
}
