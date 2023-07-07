//
// Created by amina on 3/26/2021.
//

//
// Created by amina on 3/17/2021.
//
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "D:\Uni documents\Sem2\OOP\Assignments\a45-913-Diaconu-Ana\Tests\MovieDatabaseTests.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a45-913-Diaconu-Ana\Repository\MovieRepository.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a45-913-Diaconu-Ana\Domain\DynamicVectorTemplated.h"
#include "D:\Uni documents\Sem2\OOP\Assignments\a45-913-Diaconu-Ana\UI\UI.h"
#include <crtdbg.h>

int main()
{


      MovieRepository movie_repo;
      WatchList watch_list;
      UI ui(movie_repo, watch_list);
      ui.menu();
//
//
//      MovieController controller;
//      controller.createEntries();
//      AdminUI admin_ui(controller);
//      admin_ui.main_menu();

    int r = _CrtDumpMemoryLeaks();

    printf("\n Memory leaks: %d",r);
    return 0;

}