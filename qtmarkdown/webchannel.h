#ifndef WEBCHANNEL_H
#define WEBCHANNEL_H

#include <QObject>

class QWebChannel;
class WebChannel : public QObject
{
    Q_OBJECT
public:
    explicit WebChannel(QObject *parent = 0);
    QWebChannel* channel();

signals:
    void sigWebRequest(const QString &commandName, const QString &jsonParams);

public slots:
    void request(const QString &commandName, const QString &jsonParams);

private:
    QWebChannel *m_channel;
};

#endif // WEBCHANNEL_H
