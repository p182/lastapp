/*
 * UserController.cpp
 *
 *  Created on: Aug 13, 2017
 *      Author: misha
 */

#include "UserController.hpp"
#include "LastFMCommon.hpp"
#include <QUrl>
#include <QDebug>
#include <QVariantMap>
#include <bb/data/JsonDataAccess>
#include <bb/cascades/QmlDocument>
#include "LastFM.hpp"
#include <QSettings>

using namespace bb::cascades;
using namespace bb::data;

namespace bb {
    namespace lastfm {
        namespace controllers {

            Logger UserController::logger = Logger::getLogger("UserController");

            UserController::UserController(QObject* parent) : QObject(parent) {
                m_pNetwork = QmlDocument::defaultDeclarativeEngine()->networkAccessManager();
            }

            UserController::~UserController() {
                m_pNetwork->deleteLater();
            }

            void UserController::getRecentTracks(const QString& user, const int& page, const int& limit) {
                QNetworkRequest req;

                QUrl url = LastFM::defaultUrl(USER_GET_RECENT_TRACKS);
                url.addQueryItem("user", user);
                url.addQueryItem("page", QString::number(page));
                url.addQueryItem("limit", QString::number(limit));

                req.setUrl(url);
                req.setRawHeader("Content-Type", "application/x-www-form-urlencoded");

                logger.info(url);

                QNetworkReply* reply = m_pNetwork->get(req);
                bool res = QObject::connect(reply, SIGNAL(finished()), this, SLOT(onRecentTracksLoaded()));
                Q_ASSERT(res);
                res = QObject::connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onError(QNetworkReply::NetworkError)));
                Q_ASSERT(res);
                Q_UNUSED(res);
            }

            void UserController::onRecentTracksLoaded() {
                QNetworkReply* reply = qobject_cast<QNetworkReply*>(QObject::sender());

                if (reply->error() == QNetworkReply::NoError) {
                    JsonDataAccess jda;
                    QVariantMap response = jda.loadFromBuffer(reply->readAll()).toMap().value("recenttracks").toMap();
                    QVariantList tracks = response.value("track").toList();
                    emit recentTracksLoaded(tracks);
                }

                reply->deleteLater();
            }

            void UserController::getTopArtists(const QString& user, const int& page, const int& limit, const QString& period) {
                QNetworkRequest req;

                QUrl url = LastFM::defaultUrl(USER_GET_TOP_ARTISTS);
                url.addQueryItem("user", user);
                url.addQueryItem("page", QString::number(page));
                url.addQueryItem("limit", QString::number(limit));
                url.addQueryItem("period", period);

                req.setUrl(url);
                req.setRawHeader("Content-Type", "application/x-www-form-urlencoded");

                logger.info(url);

                QNetworkReply* reply = m_pNetwork->get(req);
                reply->setProperty("period", period);
                bool res = QObject::connect(reply, SIGNAL(finished()), this, SLOT(onTopArtistsLoaded()));
                Q_ASSERT(res);
                res = QObject::connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onError(QNetworkReply::NetworkError)));
                Q_ASSERT(res);
                Q_UNUSED(res);
            }

            void UserController::onTopArtistsLoaded() {
                QNetworkReply* reply = qobject_cast<QNetworkReply*>(QObject::sender());

                if (reply->error() == QNetworkReply::NoError) {
                    JsonDataAccess jda;
                    QVariantMap response = jda.loadFromBuffer(reply->readAll()).toMap().value("topartists").toMap();
                    QVariantList artists = response.value("artist").toList();
                    QVariantMap attr = response.value("@attr").toMap();
                    emit topArtistsLoaded(artists, reply->property("period").toString(), attr.value("user").toString(), attr.value("total").toInt());
                }

                reply->deleteLater();
            }

            void UserController::getTopAlbums(const QString& user, const int& page, const int& limit, const QString& period) {
                QNetworkRequest req;

                QUrl url = LastFM::defaultUrl(USER_GET_TOP_ALBUMS);
                url.addQueryItem("user", user);
                url.addQueryItem("page", QString::number(page));
                url.addQueryItem("limit", QString::number(limit));
                url.addQueryItem("period", period);

                req.setUrl(url);
                req.setRawHeader("Content-Type", "application/x-www-form-urlencoded");

                logger.info(url);

                QNetworkReply* reply = m_pNetwork->get(req);
                reply->setProperty("period", period);
                bool res = QObject::connect(reply, SIGNAL(finished()), this, SLOT(onTopAlbumsLoaded()));
                Q_ASSERT(res);
                res = QObject::connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onError(QNetworkReply::NetworkError)));
                Q_ASSERT(res);
                Q_UNUSED(res);
            }

            void UserController::onTopAlbumsLoaded() {
                QNetworkReply* reply = qobject_cast<QNetworkReply*>(QObject::sender());

                if (reply->error() == QNetworkReply::NoError) {
                    JsonDataAccess jda;
                    QVariantMap response = jda.loadFromBuffer(reply->readAll()).toMap().value("topalbums").toMap();
                    QVariantList artists = response.value("album").toList();
                    emit topAlbumsLoaded(artists, reply->property("period").toString());
                }

                reply->deleteLater();
            }

            void UserController::getTopTracks(const QString& user, const int& page, const int& limit, const QString& period) {
                QNetworkRequest req;

                QUrl url = LastFM::defaultUrl(USER_GET_TOP_TRACKS);
                url.addQueryItem("user", user);
                url.addQueryItem("page", QString::number(page));
                url.addQueryItem("limit", QString::number(limit));
                url.addQueryItem("period", period);

                req.setUrl(url);
                req.setRawHeader("Content-Type", "application/x-www-form-urlencoded");

                logger.info(url);

                QNetworkReply* reply = m_pNetwork->get(req);
                reply->setProperty("period", period);
                reply->setProperty("user", user);
                bool res = QObject::connect(reply, SIGNAL(finished()), this, SLOT(onTopTracksLoaded()));
                Q_ASSERT(res);
                res = QObject::connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onError(QNetworkReply::NetworkError)));
                Q_ASSERT(res);
                Q_UNUSED(res);
            }

            void UserController::onTopTracksLoaded() {
                QNetworkReply* reply = qobject_cast<QNetworkReply*>(QObject::sender());

                if (reply->error() == QNetworkReply::NoError) {
                    JsonDataAccess jda;
                    QVariantMap response = jda.loadFromBuffer(reply->readAll()).toMap().value("toptracks").toMap();
                    QVariantList artists = response.value("track").toList();
                    emit topTracksLoaded(artists, reply->property("period").toString(), reply->property("user").toString());
                }

                reply->deleteLater();
            }

            void UserController::getFriends(const QString& user, const int& page, const int& limit) {
                QNetworkRequest req;

                QUrl url = LastFM::defaultUrl(USER_GET_FRIENDS);
                url.addQueryItem("user", user);
                url.addQueryItem("page", QString::number(page));
                url.addQueryItem("limit", QString::number(limit));

                req.setUrl(url);
                req.setRawHeader("Content-Type", "application/x-www-form-urlencoded");

                logger.info(url);

                QNetworkReply* reply = m_pNetwork->get(req);
                bool res = QObject::connect(reply, SIGNAL(finished()), this, SLOT(onFriendsLoaded()));
                Q_ASSERT(res);
                res = QObject::connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onError(QNetworkReply::NetworkError)));
                Q_ASSERT(res);
                Q_UNUSED(res);
            }

            void UserController::onFriendsLoaded() {
                QNetworkReply* reply = qobject_cast<QNetworkReply*>(QObject::sender());

                if (reply->error() == QNetworkReply::NoError) {
                    JsonDataAccess jda;
                    QVariantMap response = jda.loadFromBuffer(reply->readAll()).toMap().value("friends").toMap();
                    QVariantList friends = response.value("user").toList();
                    emit friendsLoaded(friends);
                }

                reply->deleteLater();
            }

            void UserController::getInfo(const QString& user) {
                QUrl url = LastFM::defaultUrl(USER_GET_INFO);
                url.addQueryItem("user", user);

                logger.info(url);

                QNetworkRequest req;
                req.setUrl(url);
                req.setRawHeader("Content-Type", "application/x-www-form-urlencoded");

                QNetworkReply* reply = m_pNetwork->get(req);
                bool res = QObject::connect(reply, SIGNAL(finished()), this, SLOT(onInfoLoaded()));
                Q_ASSERT(res);
                res = QObject::connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onError(QNetworkReply::NetworkError)));
                Q_ASSERT(res);
                Q_UNUSED(res);
            }

            void UserController::onInfoLoaded() {
                QNetworkReply* reply = qobject_cast<QNetworkReply*>(QObject::sender());

                if (reply->error() == QNetworkReply::NoError) {
                    JsonDataAccess jda;
                    QVariantMap user = jda.loadFromBuffer(reply->readAll()).toMap().value("user").toMap();
                    emit infoLoaded(user);
                }

                reply->deleteLater();
            }

            void UserController::getLovedTracks(const QString& user, const int& page, const int& limit) {
                QUrl url = LastFM::defaultUrl(USER_GET_LOVED_TRACKS);
                url.addQueryItem("user", user);
                url.addQueryItem("page", QString::number(page));
                url.addQueryItem("limit", QString::number(limit));

                QNetworkRequest req;
                req.setUrl(url);
                req.setRawHeader("Content-Type", "application/x-www-form-urlencoded");

                QNetworkReply* reply = m_pNetwork->get(req);
                bool res = QObject::connect(reply, SIGNAL(finished()), this, SLOT(onLovedTracksLoaded()));
                Q_ASSERT(res);
                res = QObject::connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(onError(QNetworkReply::NetworkError)));
                Q_ASSERT(res);
                Q_UNUSED(res);
            }

            void UserController::onLovedTracksLoaded() {
                QNetworkReply* reply = qobject_cast<QNetworkReply*>(QObject::sender());

                if (reply->error() == QNetworkReply::NoError) {
                    JsonDataAccess jda;
                    QVariantMap response = jda.loadFromBuffer(reply->readAll()).toMap().value("lovedtracks").toMap();
                    QVariantList tracks = response.value("track").toList();
                    QVariantMap attr = response.value("@attr").toMap();
                    emit lovedTracksLoaded(tracks, attr.value("user").toString(), attr.value("total").toInt());
                }

                reply->deleteLater();
            }

            void UserController::onError(QNetworkReply::NetworkError e) {
                QNetworkReply* reply = qobject_cast<QNetworkReply*>(QObject::sender());
                logger.error(e);
                logger.error(reply->errorString());
                reply->deleteLater();
                emit error();
            }

            void UserController::setAccessToken(const QString& accessToken) {
                m_accessToken = accessToken;
            }

        } /* namespace controllers */
    } /* namespace lastfm */
} /* namespace bb */
