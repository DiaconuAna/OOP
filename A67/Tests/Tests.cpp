//
// Created by amina on 4/3/2021.
//

#include "Tests.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a67-913-Diaconu-Ana\Domain\Movie.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a67-913-Diaconu-Ana\Repository\MovieRepository.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a67-913-Diaconu-Ana\Repository\WatchListRepository.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a67-913-Diaconu-Ana\Service\MovieService.h"
#include <cassert>
#include <iostream>

void Tests::testAll() {
    testDomain();
    testRepository();
    testService();
}

void Tests::testDomain() {

    std::cout<<"Domain tests are running...\n";
    Movie m1;
    Movie m2{"Ophelia 2","Fantasy",2018,20,"trailer"};
    assert(m1.getTitle()=="");
    assert(m2.getTitle()=="Ophelia 2");
    assert(m1.getTrailer()=="");
    assert(m2.getTrailer()=="trailer");
    assert(m1.getGenre()=="");
    assert(m2.getGenre()=="Fantasy");
    assert(m1.getLikesNumber()==-1);
    assert(m2.getLikesNumber()==20);
    assert(m1.getReleaseYear()==0);
    assert(m2.getReleaseYear()==2018);
    Movie m3{m2};
    assert(m3.getTitle()=="Ophelia 2");
    m3.setTitle("Hey ho");
    assert(m3.getTitle()=="Hey ho");
    m3.setGenre("Love");
    assert(m3.getGenre()=="Love");
    m3.setReleaseYear(2020);
    assert(m3.getReleaseYear() == 2020);
    m3.setLikesNumber(40);
    assert(m3.getLikesNumber()== 40);
    m3.setTrailer("h");
    assert(m3.getTrailer()=="h");

    Movie m4;
    m4 = m2;
    assert(m4.getTitle() =="Ophelia 2");
    //std::cout<<m4<<std::endl;
    assert(m2==m4);
    // std::cin>>m2;
    // std::cout<<m2;
    std::cout<<"\nDomain tests are done!\n";
}

void Tests::testRepository() {
    std::cout<<"\nRepository tests are running...\n";

//    MovieRepository movie_repo{"movies.txt"};
//    Movie m1;
//    m1.setTitle("Harry Potter POA");
//    Movie m2{"Ophelia 2","Fantasy",2018,20,"trailer"};
//    Movie m3{"The Pacific","War",2008,204,"trailer2"};
//    movie_repo.add_movie(m2,0);
//    assert(movie_repo.repo_size()==1);
//    movie_repo.add_movie(m3,0);
//    assert(movie_repo.repo_size()==2);
//    movie_repo.remove_movie(m2);
//    assert(movie_repo.repo_size()==1);
//    movie_repo.update(m3,m1);
//    Movie m4 = movie_repo.getMovie(0);
//    assert(m4.getTitle()=="Harry Potter POA");
//
//    WatchList wl{"watchlist.txt"};
//    wl.addMovie(m2,0);
//    wl.addMovie(m3,0);
//    assert(wl.list_size()==2);
//    wl.deleteMovie(m3);
//    assert(wl.list_size()==1);
//    m1 = wl.getMovie(0);

    std::cout<<"\nRepository tests are done!\n";

}

void Tests::testService() {
    std::cout<<"\nService tests are running...\n";

//    MovieRepository movie_repo{"movies.txt"};
//    WatchList watch_list{"watchlist.txt"};
//    MovieService service{movie_repo, watch_list};
//    Movie m1;
//    Movie m2{"Ophelia 2","Fantasy",2018,20,"trailer"};
//
//
//    assert(service.controller_size() == 0);
//    //service.createEntries();
//    assert(service.controller_size() == 0);
//    service.addMovie( "Harry Potter", "Fantasy", "trailer", 2001, 2939,0);
//    assert(service.controller_size() == 1);
//    service.removeMovie("Aladdin","Fantasy","https://www.youtube.com/watch?v=foyufD52aog",2019, 24);
//    assert(service.controller_size() == 0);
//    service.addMovie("Ophelia 2","Fantasy","trailer",2018, 20,0);
//    service.updateTitle(m2,"Bla");
//    Movie aux = service.getMovie(0);
//    assert(aux.getTitle() == "Bla");
//    service.updateGenre(aux,"Fantasy");
//    aux = service.getMovie(0);
//    assert(aux.getGenre() == "Fantasy");
//    service.updateTrailer(aux,"Fantasy");
//    aux = service.getMovie(0);
//    assert(aux.getTrailer() == "Fantasy");
//    service.updateLikes(aux,56);
//    aux = service.getMovie(0);
//    assert(aux.getLikesNumber() == 56);
//    service.updateReleaseYear(aux,2020);
//    aux=service.getMovie(10);
//    assert(aux.getReleaseYear()==2020);
//
//    service.addtoWatchList(m2,0);
//    assert(service.get_watchlist_size()==1);
//    service.addtoWatchList(m1,0);
//    assert(service.get_watchlist_size()==2);
//    service.removefromWatchList(m1);
//    assert(service.get_watchlist_size()==1);

    std::cout<<"\nService tests are done!\n";

}