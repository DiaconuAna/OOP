//
// Created by amina on 5/8/2021.
//

#include <QVBoxLayout>
#include <QFormLayout>
#include <sstream>
#include "GUI.h"
#include <unistd.h>
#include <QInputDialog>
#include <QMessageBox>
#include <QWidget>
#include <QLabel>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPalette>
#include <windows.h>

GUI::GUI(MovieService &s): _service{s} {
    this->initGUI(); //when the object is created, the GUI needs to be initialized
    this->connectGUI();
}

void GUI::initGUI() {
    /*
     * QPalette pal = button->palette();
pal.setColor(QPalette::Button, QColor(Qt::blue));
button->setAutoFillBackground(true);
button->setPalette(pal);
button->update();
     */
    QPalette pal = palette();
    QFont font1("Courier New");
    QFont font2("Bookman Old Style");
    pal.setColor(QPalette::Button, QColor(Qt::cyan));

    this->UserButton = new QPushButton{"User mode"};
    this->UserButton->setStyleSheet("background-color: gray");
    this->UserButton->setFont(font2);
    this->UserButton->resize(500,300);

    this->AdminButton = new QPushButton{"Administrator mode"};
    this->AdminButton->setStyleSheet("background-color: gray");
    this->AdminButton->setFont(font2);
    this->AdminButton->resize(500,300);


    this->BarChart = new QPushButton{"Bar Chart representing Movie Categories"};
    this->BarChart->setStyleSheet("background-color: gray");
    this->BarChart->setFont(font2);
    this->BarChart->resize(500,300);


    this->exit = new QPushButton{"Exit"};
    this->exit->setStyleSheet("background-color: gray");
    this->exit->setFont(font2);
    this->exit->resize(500,300);


    this->exitAdminMode = new QPushButton{"Exit Administrator Mode"};
    this->exitAdminMode->setStyleSheet("background-color: gray");
    this->exitAdminMode->setFont(font2);

    this->exitUserMode = new QPushButton{"Exit User Mode"};
    this->exitUserMode->setStyleSheet("background-color: gray");
    this->exitUserMode->setFont(font2);

    QVBoxLayout* MainMenuLayout = new QVBoxLayout{this};


    MainMenuLayout->addWidget(this->UserButton);
    MainMenuLayout->addWidget(this->AdminButton);
    MainMenuLayout->addWidget(this->BarChart);
    MainMenuLayout->addWidget(this->exit);

    this->AdministratorWidget = new QWidget{};
    this->UserWidget = new QWidget{};

    this->updateWidget = new QWidget{};
    this->updateWidget->hide();

    this->AdministratorWidget->hide();
    this->UserWidget->hide();

    //initialising the buttons
    this->listMovie = new QPushButton{"List movies"};
    this->listMovie->setStyleSheet("background-color: gray");
    this->listMovie->setFont(font2);

    this->addMovie = new QPushButton{"Add a movie"};
    this->addMovie->setStyleSheet("background-color: gray");
    this->addMovie->setFont(font2);

    this->deleteMovie = new QPushButton{"Delete a movie"};
    this->deleteMovie->setStyleSheet("background-color: gray");
    this->deleteMovie->setFont(font2);

    this->updateMovie = new QPushButton{"Update a movie"};
    this->updateMovie->setStyleSheet("background-color: gray");
    this->updateMovie->setFont(font2);

    this->updateLikes = new QPushButton{"Update the like number"};
    this->updateLikes->setStyleSheet("background-color: gray");
    this->updateLikes->setFont(font2);

    this->updateGenre = new QPushButton{"Update the genre"};
    this->updateGenre->setStyleSheet("background-color: gray");
    this->updateGenre->setFont(font2);

    this->updateTitle = new QPushButton{"Update the title"};
    this->updateTitle->setStyleSheet("background-color: gray");
    this->updateTitle->setFont(font2);

    this->updateYear  = new QPushButton{"Update the year of release"};
    this->updateYear->setStyleSheet("background-color: gray");
    this->updateYear->setFont(font2);

    this->updateTrailer = new QPushButton{"Update the trailer"};
    this->updateTrailer->setStyleSheet("background-color: gray");
    this->updateTrailer->setFont(font2);

    this->seeDatabase = new QPushButton{"See movies in the database filtered by genre"};
    this->seeDatabase->setStyleSheet("background-color: gray");
    this->seeDatabase->setFont(font2);

    this->removeMovieUser = new QPushButton{"Remove movie from watchlist"};
    this->removeMovieUser->setStyleSheet("background-color: gray");
    this->removeMovieUser->setFont(font2);

    this->seeWatchList = new QPushButton{"See movies from watchlist"};
    this->seeWatchList->setStyleSheet("background-color: gray");
    this->seeWatchList->setFont(font2);

    this->seeCSVHTML = new QPushButton{"See the watchlist in CSV/HTML format"};
    this->seeCSVHTML->setStyleSheet("background-color: gray");
    this->seeCSVHTML->setFont(font2);


   // this->addButton = new QPushButton{"Add movie"};

    //this->MovieWidget = new QWidget{};
    //this->MovieVL = new QVBoxLayout{this->MovieWidget};
   // this->MovieLayout = new QFormLayout{};

  //  this->title = new QLineEdit{};
   // this->genre = new QLineEdit{};
   // this->trailer = new QLineEdit{};
  //  this->likes = new QLineEdit{};
  //  this->year = new QLineEdit{};

  //  this->MovieLayout->addRow("Title: ", title);
  //  this->MovieLayout->addRow("Genre: ", genre);
  //  this->MovieLayout->addRow("Number of Likes: ", likes);
  //  this->MovieLayout->addRow("Year of release: ", year);
  //  this->MovieLayout->addRow("Trailer: ", trailer);
//
  //  this->MovieVL->addLayout(this->MovieLayout);
  //  this->MovieVL->addWidget(this->addButton);

}

void GUI::connectGUI() {
    QObject::connect(this->AdminButton, &QPushButton::clicked, this, &GUI::adminMenuGUI);
    QObject::connect(this->exit, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(this->exitAdminMode, SIGNAL(clicked()), this->AdministratorWidget, SLOT(close()));
    QObject::connect(this->exitUserMode, SIGNAL(clicked()), this->UserWidget, SLOT(close()));
    QObject::connect(this->listMovie, &QPushButton::clicked, this, &GUI::listMovies);
    // QObject::connect(this, SIGNAL(addMovieSignal(Movie)), this, SLOT(addMovieAux(Movie)));
    // QObject::connect(this->addButton, &QPushButton::clicked, this, &GUI::addMovieAux);
    //  QObject::connect(this->addMovie, &QPushButton::clicked, this, &GUI::addMovieF);
    QObject::connect(this->addMovie, &QPushButton::clicked, this, &GUI::addMovieAux);
    QObject::connect(this->deleteMovie, &QPushButton::clicked, this, &GUI::deleteMovieAux);
    QObject::connect(this->updateMovie, &QPushButton::clicked, this, &GUI::updateMenu);
    QObject::connect(this->updateTitle, &QPushButton::clicked, this, &GUI::updateTitleAux);
    QObject::connect(this->updateGenre, &QPushButton::clicked, this, &GUI::updateGenreAux);
    QObject::connect(this->updateTrailer, &QPushButton::clicked, this, &GUI::updateTrailerAux);
    QObject::connect(this->updateYear, &QPushButton::clicked, this, &GUI::updateYearAux);
    QObject::connect(this->updateLikes, &QPushButton::clicked, this, &GUI::updateLikesAux);
    QObject::connect(this->UserButton, &QPushButton::clicked, this, &GUI::userMenuGUI);
    QObject::connect(this->seeWatchList, &QPushButton::clicked, this, &GUI::seeWatchListAux);
    QObject::connect(this->removeMovieUser, &QPushButton::clicked, this, &GUI::removeMovieUserAux);
    QObject::connect(this->seeCSVHTML, &QPushButton::clicked, this, &GUI::seeCSVHTMLAux);
    QObject::connect(this->seeDatabase, &QPushButton::clicked, this, &GUI::seeDatabaseAux);
    QObject::connect(this->BarChart, &QPushButton::clicked, this, &GUI::viewBarChart);


}

void GUI::adminMenuGUI() {
    auto* adminLayout = new QVBoxLayout{this->AdministratorWidget};
    adminLayout->addWidget(this->addMovie);
    adminLayout->addWidget(this->deleteMovie);
    adminLayout->addWidget(this->updateMovie);
    adminLayout->addWidget(this->listMovie);
    adminLayout->addWidget(this->exitAdminMode);

    QPalette pal = palette();
    pal.setColor(QPalette::Background,  QColor(53,53,53));
    this->AdministratorWidget->setAutoFillBackground(true);
    this->AdministratorWidget->setPalette(pal);


//    QPalette pal1 = this->addButton->palette();
//    pal1.setColor(QPalette::Button, Qt::cyan);
//    //this->addMovie->setAutoFillBackground(true);
//    this->addMovie->setPalette(pal1);
//    this->addMovie->update();



    this->AdministratorWidget->resize(300,300);
    this->AdministratorWidget->show();

}


void GUI::userMenuGUI() {
    auto* userLayout = new QVBoxLayout{this->UserWidget};
    userLayout->addWidget(this->seeDatabase);
    userLayout->addWidget(this->removeMovieUser);
    userLayout->addWidget(this->seeWatchList);
    userLayout->addWidget(this->seeCSVHTML);
    userLayout->addWidget(this->exitUserMode);

    QPalette pal = palette();
    pal.setColor(QPalette::Background,  QColor(53,53,53));
    // pal.setColor(QPalette::Button, QColor(88,102,95));
    this->UserWidget->setAutoFillBackground(true);
    this->UserWidget->setPalette(pal);

    this->UserWidget->resize(300,300);


    this->UserWidget->show();
}

void GUI::updateMenu() {
    auto* updateLayout = new QVBoxLayout{this->updateWidget};
    updateLayout->addWidget(this->updateTitle);
    updateLayout->addWidget(this->updateGenre);
    updateLayout->addWidget(this->updateTrailer);
    updateLayout->addWidget(this->updateYear);
    updateLayout->addWidget(this->updateLikes);

    QPalette pal = palette();
    pal.setColor(QPalette::Background,  QColor(53,53,53));
    // pal.setColor(QPalette::Button, QColor(88,102,95));
    this->updateWidget->setAutoFillBackground(true);
    this->updateWidget->setPalette(pal);

    this->updateWidget->resize(300,300);

    this->updateWidget->show();
}


void GUI::seeWatchListAux() {
    auto* watchListWidget = new QListWidget{};
    std::vector<Movie> wl = this->_service.getWatchList();

    for(const auto& m:wl){
        watchListWidget->addItem(QString::fromStdString(toString(const_cast<Movie &>(m))));
        //watchListWidget->setAlternatingRowColors(true);
        }

    QFont font("Courier New");
    watchListWidget->setFont(font);
    watchListWidget->setStyleSheet("alternate-background-color: white;background-color: grey;");
    watchListWidget->setAlternatingRowColors(true);
    watchListWidget->resize(500,500);
    watchListWidget->show();
}


void GUI::listMovies() {
 auto* movieListWidget = new QListWidget{};


 //start from an empty list each time
 std::vector<Movie> movies = this->_service.getMovieList();

 for(const auto& m: movies)
     movieListWidget->addItem(QString::fromStdString(toString(const_cast<Movie &>(m))));

 QFont font("Courier New");
 movieListWidget->setFont(font);
 movieListWidget->setStyleSheet("alternate-background-color: white;background-color: grey;");
 movieListWidget->setAlternatingRowColors(true);
 movieListWidget->resize(500,500);
 movieListWidget->show();


}

std::string GUI::toString(Movie& mov)  {
    std::stringstream buff;
    buff<<"Title: "<<mov.getTitle()<<std::endl;
    buff<<"Genre: "<<mov.getGenre()<<std::endl;
    buff<<"Release Year: "<<mov.getReleaseYear()<<std::endl;
    buff<<"Number of likes: "<<mov.getLikesNumber()<<std::endl;
    buff<<"Trailer link: "<<mov.getTrailer()<<std::endl;

    return buff.str();
}

void GUI::addMovieF() {

    auto* title = new QLineEdit{};
    auto* genre = new QLineEdit{};
    auto* trailer = new QLineEdit{};
    auto* likes = new QLineEdit{};
    auto *year = new QLineEdit{};


    auto* addMovieWidget = new QWidget{};
    auto* addVL = new QVBoxLayout{addMovieWidget};
    auto* addLayout = new QFormLayout{};


    addLayout->addRow("Title: ", title);
    addLayout->addRow("Genre: ", genre);
    addLayout->addRow("Number of Likes: ", likes);
    addLayout->addRow("Year of release: ", year);
    addLayout->addRow("Trailer: ", trailer);

    addVL->addLayout(addLayout);
    addVL->addWidget(this->addButton);
    addMovieWidget->show();




    std::string m_title = title->text().toStdString();
    std::string m_genre = genre->text().toStdString();
    std::string m_likes = likes->text().toStdString();
    std::string m_year = year->text().toStdString();
    std::string m_trailer =  trailer->text().toStdString();

    int like;
    if(m_likes == "0")
        like = -1;
    else
        like = atoi(m_likes.c_str());

    if(like == 0)
        like = -1;
    else if(like == -1)
        like = 0;

      int years;
      years = atoi(m_year.c_str());

    this->_working_mov = Movie(m_title, m_genre, years, like, m_trailer);
    std::cout<<this->_working_mov;


    //emit addMovieSignal(Movie(m_title, m_genre, years, like, m_trailer));

}

void GUI::addMovieAux() {
    std::string m_title = QInputDialog::getText(this->AdministratorWidget, "Add movie","Title: ").toStdString();
    std::string m_genre = QInputDialog::getText(this->AdministratorWidget, "Add movie", "Genre: ").toStdString();
    std::string m_trailer = QInputDialog::getText(this->AdministratorWidget, "Add movie", "Trailer: ").toStdString();


    int likes = QInputDialog::getInt(this->AdministratorWidget, "Add movie", "Number of likes: ");
    int years = QInputDialog::getInt(this->AdministratorWidget, "Add movie","Year of release: ");

    try{
        this->_service.addMovie(m_title, m_genre, m_trailer,years, likes, 0);
    }
    catch (const ValidationException &ve){

        QMessageBox msg;
        msg.setText(QString::fromStdString(ve.get_message()));
        msg.exec();
    }
    catch (const RepositoryException &re){
        QMessageBox msg;
        msg.setText(QString::fromStdString(re.get_message()));
        msg.exec();
    }
}

void GUI::deleteMovieAux() {
    std::string m_title = QInputDialog::getText(this->AdministratorWidget, "Delete movie","Title: ").toStdString();


    try{
        this->_service.removeMovie(m_title,"","",0,0);
    }
    catch (const RepositoryException &re){
        QMessageBox msg;
        msg.setText(QString::fromStdString(re.get_message()));
        msg.exec();
    }

}

void GUI::updateTitleAux() {
    std::string old_title =  QInputDialog::getText(this->updateWidget, "Update movie","Old Title: ").toStdString();
    std::string new_title = QInputDialog::getText(this->updateWidget, "Update movie", "New Title: ").toStdString();

    try{
        this->_service.updateTitle(Movie(old_title,"",0,-1,""), new_title);
    }
    catch (const ValidationException &ve) {
        QMessageBox msg;
        msg.setText(QString::fromStdString(ve.get_message()));
        msg.exec();
    }
    catch (const RepositoryException &re){
        QMessageBox msg;
        msg.setText(QString::fromStdString(re.get_message()));
        msg.exec();
    }


}

void GUI::updateGenreAux() {
    std::string old_title =  QInputDialog::getText(this->updateWidget, "Update movie","Movie Title: ").toStdString();
    std::string new_genre = QInputDialog::getText(this->updateWidget, "Update movie", "New Genre: ").toStdString();

    try{
        this->_service.updateGenre(Movie(old_title,"",0,0,""), new_genre);
    }
    catch (const ValidationException &ve) {
        QMessageBox msg;
        msg.setText(QString::fromStdString(ve.get_message()));
        msg.exec();
    }
    catch (const RepositoryException &re){
        QMessageBox msg;
        msg.setText(QString::fromStdString(re.get_message()));
        msg.exec();
    }

}

void GUI::updateTrailerAux() {
    std::string old_title =  QInputDialog::getText(this->updateWidget, "Update movie","Movie Title: ").toStdString();
    std::string new_trailer = QInputDialog::getText(this->updateWidget, "Update movie", "New Trailer: ").toStdString();

    try{
        this->_service.updateTrailer(Movie(old_title,"",0,0,""), new_trailer);
    }
    catch (const ValidationException &ve) {
        QMessageBox msg;
        msg.setText(QString::fromStdString(ve.get_message()));
        msg.exec();
    }
    catch (const RepositoryException &re){
        QMessageBox msg;
        msg.setText(QString::fromStdString(re.get_message()));
        msg.exec();
    }

}

void GUI::updateYearAux() {
    std::string old_title =  QInputDialog::getText(this->updateWidget, "Update movie","Movie Title: ").toStdString();
    int year = QInputDialog::getInt(this->updateWidget, "Update movie", "New year of release: ");

    try{
        this->_service.updateReleaseYear(Movie(old_title,"",0,0,""), year);
    }
    catch (const ValidationException &ve) {
        QMessageBox msg;
        msg.setText(QString::fromStdString(ve.get_message()));
        msg.exec();
    }
    catch (const RepositoryException &re){
        QMessageBox msg;
        msg.setText(QString::fromStdString(re.get_message()));
        msg.exec();
    }

}

void GUI::updateLikesAux() {
    std::string old_title =  QInputDialog::getText(this->updateWidget, "Update movie","Movie Title: ").toStdString();
    int likes = QInputDialog::getInt(this->updateWidget, "Update movie", "New number of likes: ");

    try{
        this->_service.updateLikes(Movie(old_title,"",0,0,""), likes);
    }
    catch (const ValidationException &ve) {
        QMessageBox msg;
        msg.setText(QString::fromStdString(ve.get_message()));
        msg.exec();
    }
    catch (const RepositoryException &re){
        QMessageBox msg;
        msg.setText(QString::fromStdString(re.get_message()));
        msg.exec();
    }
}


void GUI::seeDatabaseAux() {
    std::string genre = QInputDialog::getText(this->UserWidget, "Database","Genre: ").toStdString();
//    QMessageBox msg;
//    msg.setText(QString::fromStdString("To be continued!"));
//    msg.exec();

    std::vector<Movie> movie_list = this->_service.filterByGenre(genre);
    int len = movie_list.size();
    if(len == 0) {

            QMessageBox msg;
            msg.setText("Invalid genre.");
            msg.exec();

    }
    else {

        for (int i = 0; i < len; i++) {
            std::string movie_details = this->toString(movie_list[i]);
            ShellExecute(NULL,"open",movie_list[i].getTrailer().c_str(),NULL, NULL, SW_SHOWNORMAL);
            QLabel label{movie_details.c_str()};
            label.show();
            QMessageBox::StandardButton add = QMessageBox::question(this, "Database",
                                                                    "Would you like to add the movie to the watchlist?",
                                                                    QMessageBox::Yes | QMessageBox::No);
            if (add == QMessageBox::Yes) {
                try {
                    this->_service.addtoWatchList(movie_list[i], 0);
                }
                catch (const RepositoryException &re) {
                    QMessageBox msg;
                    msg.setText(QString::fromStdString(re.get_message()));
                    msg.exec();
                }
            }
            QMessageBox::StandardButton next = QMessageBox::question(this, "Database",
                                                                     "Would you like to see the next movie?",
                                                                     QMessageBox::Yes | QMessageBox::No);
            if (next == QMessageBox::Yes && i == len - 1) {
                i = -1;
            } else if (next == QMessageBox::No)
                break;
        }
    }

}

void GUI::removeMovieUserAux() {
    std::string title = QInputDialog::getText(this->UserWidget, "Remove movie WL","Title: ").toStdString();
    int ok = 0;
    Movie mov = Movie(title,"",0,-1,"");
    try{
    this->_service.removefromWatchList(mov);}
    catch (const RepositoryException &re){
        QMessageBox msg;
        msg.setText(QString::fromStdString(re.get_message()));
        msg.exec();
        ok = 1;
    }

  if(!ok){
    QMessageBox::StandardButton like = QMessageBox::question(this, "Like/Dislike", "Would you like to rate a movie with a like?", QMessageBox::Yes | QMessageBox::No);

    if (like == QMessageBox::Yes){
    //std::cout<<mov<<std::endl;
        this->_service.rate_movie(mov);
    }
  }
}

void GUI::seeCSVHTMLAux() {
   // QMessageBox msg;
   // msg.setText(QString::fromStdString("Good job!"));
  //  msg.exec();
  this->_service.see_watchlist();
}

void GUI::viewBarChart() {


    QFont font("Courier New");
    QFont font2("Bahnschrift Light");
    QWidget* genreChart = new QWidget{};

     QBarSet *genre0 = new QBarSet("War");
     QBarSet *genre1 = new QBarSet("Fantasy");
     QBarSet *genre2 = new QBarSet("Comedy");
     QBarSet *genre3 = new QBarSet("Romance");
     QBarSet *genre4 = new QBarSet("Animation");
     QBarSet *genre5 = new QBarSet("Drama");

    *genre0 << this->_service.filterByGenre("War").size();
    *genre1 << this->_service.filterByGenre("Fantasy").size();
    *genre2 << this->_service.filterByGenre("Comedy").size();
    *genre3 << this->_service.filterByGenre("Romance").size();
    *genre4 << this->_service.filterByGenre("Animation").size();
    *genre5 << this->_service.filterByGenre("Drama").size();


    QBarSeries *genrea0 = new QBarSeries();
    genrea0->append(genre0);
    QBarSeries *genrea1 = new QBarSeries();
    genrea1->append(genre1);
    QBarSeries *genrea2 = new QBarSeries();
    genrea2->append(genre2);
    QBarSeries *genrea3 = new QBarSeries();
    genrea3->append(genre3);
    QBarSeries *genrea4 = new QBarSeries();
    genrea4->append(genre4);
    QBarSeries *genrea5 = new QBarSeries();
    genrea5->append(genre5);

    auto *movieGenreChart = new QChart();
    movieGenreChart->addSeries(genrea0);
    movieGenreChart->addSeries(genrea1);
    movieGenreChart->addSeries(genrea2);
    movieGenreChart->addSeries(genrea3);
    movieGenreChart->addSeries(genrea4);
    movieGenreChart->addSeries(genrea5);

    movieGenreChart->setTitle("Movie Categories");
    movieGenreChart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
   // QStringList movie;
    categories<<"Movie genres";
   // movie<<"Number of movies";
//    QStringList war;
//    war<<"War";
//    QStringList fantasy;
//    fantasy<<"Fantasy";
//    categories << QString::fromStdString(std::to_string(this->_service.filterByGenre("War").size()));
//    categories << QString::fromStdString(std::to_string(this->_service.filterByGenre("Fantasy").size()));
//    categories << QString::fromStdString(std::to_string(this->_service.filterByGenre("Comedy").size()));
//    categories << QString::fromStdString(std::to_string(this->_service.filterByGenre("Romance").size()));
//    categories << QString::fromStdString(std::to_string(this->_service.filterByGenre("Animation").size()));
//    categories << QString::fromStdString(std::to_string(this->_service.filterByGenre("Drama").size()));
    //categories<<"War"<<"Fantasy"<<"Comedy"<<"Romance"<<"Animation"<<"Drama";

    auto *axisX = new QBarCategoryAxis();
    axisX->setTitleText("Movie genres");
    axisX->setTitleFont(font);
   // axisX->append(categories);
   // axisX->append(fantasy);
    movieGenreChart->addAxis(axisX, Qt::AlignBottom);
    genrea0->attachAxis(axisX);
    genrea1->attachAxis(axisX);
    genrea2->attachAxis(axisX);
    genrea3->attachAxis(axisX);
    genrea4->attachAxis(axisX);
    genrea5->attachAxis(axisX);



    auto *axisY = new QValueAxis();
    axisY->setTitleText("Number of movies");
    axisY->setTitleFont(font);
    axisY->setRange(0,8);
    //axisY->setTickCount(2);
    movieGenreChart->addAxis(axisY, Qt::AlignLeft);
    genrea0->attachAxis(axisY);
    genrea1->attachAxis(axisY);
    genrea2->attachAxis(axisY);
    genrea3->attachAxis(axisY);
    genrea4->attachAxis(axisY);
    genrea5->attachAxis(axisY);


    movieGenreChart->legend()->setVisible(true);
    movieGenreChart->legend()->setAlignment(Qt::AlignBottom);

    auto *chartView = new QChartView(movieGenreChart, genreChart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QPalette pal = palette();
    pal.setColor(QPalette::Background,  QColor(53,53,53));

    chartView->resize(1000,1000);
    chartView->setStyleSheet("background-color: gray");
    genreChart->resize(1000,1000);


    // pal.setColor(QPalette::Button, QColor(88,102,95));
    genreChart->setAutoFillBackground(true);
    genreChart->setPalette(pal);
    genreChart->show();

}



