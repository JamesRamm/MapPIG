#ifndef DATAREQUESTS_H
#define DATAREQUESTS_H

#include <QObject>
#include <QString>
#include <QtSql>
#include <stdlib.h>

/**
 * @brief The DataRequests class
 *          Handles requests for JCALF data
 */
class DataRequests : public QObject
{
    Q_OBJECT
public:
    explicit DataRequests(QObject *parent = 0);
    ~DataRequests();
    QSqlDatabase jcalfDb;
    std::map<QString, std::vector<double> *> portfolioTiv;

signals:
    void riskUpdated(double lat, double lng, double tiv);
    void workFinished();
    void workStarted();
    void progressUpdated(int perc);
    void databaseConnected(bool status);
    void error(QString err, QString title);
    void markerLoadingStats(int nLoaded, int nSkipped);

public slots:

    void refreshExposures(double minX, double minY, double maxX, double maxY);
    void getLastError();
    void setJcalfDatabase(QString host, QString port, QString user, QString pwd);
    void loadCsv(QString fpath);

    /**
     * @brief computeHist
     *  Get the histogram for a previously loaded portfolio
     * @param fpath
     */
    void computeHist(QString fpath);

};

#endif // DATAREQUESTS_H
