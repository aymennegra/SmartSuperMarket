#include "notification.h"
#include <QSystemTrayIcon>

notification::notification()
{
  num=0;
}
void notification::notification_ajout(int number)
{
    number=num;
       QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
       notifyIcon->show();
       notifyIcon->setIcon(QIcon("icon.png"));
       QString s = QString::number(number);
       notifyIcon->showMessage("Ajout point d'acces","Un nouveau point d'acces de  N° REF"+s+" a été ajoutée",QSystemTrayIcon::Information,15000);
   num++;
}
