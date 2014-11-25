#ifndef BUSREADER_H
#include <QObject>

#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <QGuiApplication>
#include <QQuickView>
#include <QtQml>
#define BUSREADER_H

class BusReader: public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE bool postMessage(const QString &msg);
    Q_INVOKABLE QString getBus(const QString &msg);
    Q_PROPERTY(QString html   READ html   WRITE setHtml   NOTIFY htmlChanged)
    const QString html ( ) const;
    void setHtml(const QString &newHtml);



public slots:
    void refresh();
    void handleNetworkData(QNetworkReply *networkReply);

private:
    QNetworkAccessManager networkManager;
    QString s_html;

signals:
    void htmlChanged();

};
#endif // BUSREADER_H
