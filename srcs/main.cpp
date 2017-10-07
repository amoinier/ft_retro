/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 09:15:10 by amoinier          #+#    #+#             */
/*   Updated: 2017/10/07 21:45:07 by amoinier         ###   ########.fr       */
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
	Game *game = new Game(10);
	int ch = -1;


	while (1) {
		// if (ch == 401) {
		// 	game->setBox(&box);
		// 	wborder(game->getBox(), '|', '|', '-', '-', '*', '*', '*', '*');
		// }
		ch = getch();
		game->printMap();
		wborder(game->getBox(), '|', '|', '-', '-', '*', '*', '*', '*');
		wrefresh(game->getBox());
		game->play(ch);

		usleep(10000);
	}

	endwin();
	return (0);
}
