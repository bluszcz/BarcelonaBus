#include "BusReader.h"

 bool BusReader::postMessage(const QString &msg) {
    qDebug() << "Called the C++ method with" << msg;
    return true;
}

 QString BusReader::getBus(const QString &msg) {
    //QString str = "Hello";
     QNetworkRequest newRequest("http://www.tmb.cat/piu/ca_ES/piuimodesolucio.jsp?parada="+msg);
     networkManager.get(newRequest);
     connect(&networkManager, SIGNAL(finished(QNetworkReply*)),
                 this, SLOT(handleNetworkData(QNetworkReply*)));
    return msg;
 }


 void BusReader::handleNetworkData(QNetworkReply *networkReply)
 {
     QUrl url = networkReply->url();
     if (!networkReply->error()) {

         QString response = QString::fromLatin1(networkReply->readAll());
         qDebug() << response;




         response = response.replace("bgcolor=\"#99CCFF\"","");


         setHtml(response);

     }

     networkReply->deleteLater();
 }


 const QString BusReader :: html ( ) const {
     return s_html;
 }

void BusReader::setHtml(const QString &newHtml)
{
     s_html = newHtml;
     emit htmlChanged ();
}

void BusReader::refresh() {
    qDebug() << "Called the C++ slot";
}


