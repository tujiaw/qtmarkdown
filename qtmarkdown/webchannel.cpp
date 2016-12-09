#include "webchannel.h"
#include <QWebChannel>

WebChannel::WebChannel(QObject *parent)
    : QObject(parent)
    , m_channel(new QWebChannel(this))
{
    m_channel->registerObject("WebChannel", this);
}

QWebChannel* WebChannel::channel()
{
    return m_channel;
}

void WebChannel::request(const QString &commandName, const QString &jsonParams)
{
    emit sigWebRequest(commandName, jsonParams);
}
