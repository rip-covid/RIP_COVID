#include "MyHeader.h"

extern humanCurPosX, humanCurPosY;
extern v_num;
extern vertical_num;

//바이러스 충돌 검사
int DetectCollisionV() {
	int i, j;

	for (i = 0; i < 10; i++) {
		if (virus[i].x == humanCurPosX && virus[i].y == humanCurPosY) {
			return 2;
		}
	}
	for (i = 0; i < v_num; i++) {
		if (virusOneby[i].x == humanCurPosX && virusOneby[i].y == humanCurPosY) {
			return 2;
		}
	}

	for (i = 0; i < GBOARD_HEIGHT - 2; i++) {
		if (virusVertical[i].x == humanCurPosX && virusVertical[i].y == humanCurPosY) {
			return 2;
		}
	}
	return 1;
}

//충돌 검사
int DetectCollision(int posX, int posY) {

	if (posX == 1 || posX + 1 > GBOARD_WIDTH - 3 || posY == 0 || posY == GBOARD_HEIGHT - 1)
		return 0;

	return 1;
}


//추적 바이러스
void trackingVirus() {

	for (int i = 0; i < 5; i++) {
		SetCurrentCursorPos(virus[i].x, virus[i].y);
		printf(" ");

		int x, y;
		x = virus[i].x - humanCurPosX;
		y = virus[i].y - humanCurPosY;

		if (x == 0 && y == 0)
			continue;
		else if (x == 0) {
			if (y > 0)
				virus[i].y--;
			else
				virus[i].y++;
		}
		else if (y == 0) {
			if (x > 0)
				virus[i].x--;
			else
				virus[i].x++;
		}
		else if (x > 0 && y > 0) {
			virus[i].x--;
			virus[i].y--;
		}
		else if (x > 0 && y < 0) {
			virus[i].x--;
			virus[i].y++;
		}
		else if (x < 0 && y > 0) {
			virus[i].x++;
			virus[i].y--;
		}
		else {
			virus[i].x++;
			virus[i].y++;
		}

		RED
			SetCurrentCursorPos(virus[i].x, virus[i].y);
		printf("*");
	}
	WHITE
}

void trackingVirusOneby() {

	for (int i = 0; i < v_num; i++) {
		SetCurrentCursorPos(virusOneby[i].x, virusOneby[i].y);
		printf(" ");

		int x, y;
		x = virusOneby[i].x - humanCurPosX;
		y = virusOneby[i].y - humanCurPosY;

		if (x == 0 && y == 0)
			continue;
		else if (x == 0) {
			if (y > 0)
				virusOneby[i].y--;
			else
				virusOneby[i].y++;
		}
		else if (y == 0) {
			if (x > 0)
				virusOneby[i].x--;
			else
				virusOneby[i].x++;
		}
		else if (x > 0 && y > 0) {
			virusOneby[i].x--;
			virusOneby[i].y--;
		}
		else if (x > 0 && y < 0) {
			virusOneby[i].x--;
			virusOneby[i].y++;
		}
		else if (x < 0 && y > 0) {
			virusOneby[i].x++;
			virusOneby[i].y--;
		}
		else {
			virusOneby[i].x++;
			virusOneby[i].y++;
		}

		RED
			SetCurrentCursorPos(virusOneby[i].x, virusOneby[i].y);
		printf("*");
	}
	vertical_num++;
	WHITE
}

void trackingVirusVertical() {

	if (virusVertical[0].x + 4 > GBOARD_WIDTH) {
		for (int i = 0; i < GBOARD_HEIGHT - 2; i++) {
			SetCurrentCursorPos(virusVertical[i].x, virusVertical[i].y);
			printf(" ");
		}
		return;
	}

	for (int i = 0; i < GBOARD_HEIGHT - 2; i++) {
		if (virusVertical[i].visible == 1) {
			SetCurrentCursorPos(virusVertical[i].x, virusVertical[i].y);
			printf(" ");

			virusVertical[i].x++;

			RED
				SetCurrentCursorPos(virusVertical[i].x, virusVertical[i].y);
			printf("*");
		}
	}
	WHITE
}