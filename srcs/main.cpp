/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 09:15:10 by amoinier          #+#    #+#             */
/*   Updated: 2017/10/07 16:18:31 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include "Game.hpp"

//0 <= y0 < LINES;
//0 <= x0 < COLUMNS;

//ESCAPE = 27
//SPACEBAR = 32

int main(void)
{
	std::cout << "1" << std::endl;
	WINDOW *box;
	std::cout << "2" << std::endl;
	Game *game = new Game(&box, COLS, LINES);
	std::cout << "3" << std::endl;
	int ch = -1;

	initscr();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(0);
	std::cout << "4" << std::endl;

	box = subwin(stdscr,LINES, COLS, 0, 0);
	wborder(box, '|', '|', '-', '-', '*', '*', '*', '*');
	std::cout << "5" << std::endl;

	while (1) {
		if (ch == 401) {
			box = subwin(stdscr,LINES, COLS, 0, 0);
			wborder(box, '|', '|', '-', '-', '*', '*', '*', '*');
		}

		ch = getch();
		game->printMap();
		wrefresh(game->getBox());
		game->eraseMap();
	}

	return (0);
}


//
// int main(void) {
// 	int ch;
// 	int x = 0;
// 	int y = 0;
// 	float i = 0;
//
// 	initscr();
// 	nodelay(stdscr, TRUE);
// 	keypad(stdscr, TRUE);
// 	// scrollok(stdscr, TRUE);
// 	curs_set(0);
//
// 	while (1) {
// 		box = subwin(stdscr,LINES, COLS, 0, 0);
// 		wborder(box, '|', '|', '-', '-', '*', '*', '*', '*');
// 		ch = getch();
// 		mvwaddch(box, i, COLS / 2, '&');
//
// 		mvwaddch(box, LINES / 2 + y, COLS / 2 + x, '&');
// 		wrefresh(box);
// 		//mvwdelch(box, LINES / 2 + y, COLS / 2 + x);
// 		mvwaddch(box, LINES / 2 + y, COLS / 2 + x, ' ');
//
// 		//mvwdelch(box, i, COLS / 2);
// 		mvwaddch(box, i, COLS / 2, ' ');
//
// 		if (ch == 401) {
// 			werase(box);
// 		}
//
// 		if (ch == 27) {
// 			break ;
// 		}
// 		if (ch == 261) {
// 			x++;
// 		}
// 		if (ch == 260) {
// 			x--;
// 		}
// 		if (ch == 258) {
// 			y++;
// 		}
// 		if (ch == 259) {
// 			y--;
// 		}
//
// 		i += 0.2;
//
// 		usleep(20000);
// 	}
//
//     endwin();
//
// 	return 0;
// }
