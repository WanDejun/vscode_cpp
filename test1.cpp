#include <graphics.h>

typedef struct {
	double x, y;
	int x_size, y_size;
	color_t color;
} Rect;

static void RectShow(Rect rect) {
	setfillcolor(rect.color);

	ege_fillrect(float(rect.x), float(rect.y), float(rect.x_size), float(rect.y_size));
}

int main() {
	initgraph(1280, 720);
	setbkcolor(EGEARGB(255, 0xff, 0xff, 0xff));

	Rect rect{ 615, 335, 50, 50 }; rect.color = EGEARGB(192, 121, 236, 213);
	Rect rect_bk{ random(1000), random(600), 50, 50 }; rect_bk.color = EGEACOLOR(192, RED);

	key_msg msg;

	double speed = 2.5;
	double dx = 0, dy = 0, dx_bk = speed, dy_bk = speed;

	RectShow(rect);

	for (; is_run(); delay_fps(60)) {
		msg = { 0 };
		cleardevice();

		if (rect_bk.x >= 1255 || rect_bk.x <= 25) dx_bk = -dx_bk;
		if (rect_bk.y >= 695 || rect_bk.y <= 25) dy_bk = -dy_bk;
		rect_bk.x += dx_bk; rect_bk.y += dy_bk;

		if (kbmsg()) {
			msg = getkey();

			switch (msg.key) {
			case 119: //w
				if (msg.msg == key_msg_char)
					dy = -speed;
				dx = 0;
				break;
			case 97: //a
				if (msg.msg == key_msg_char)
					dx = -speed;
				dy = 0;
				break;
			case 115: //s
				if (msg.msg == key_msg_char)
					dy = speed;
				dx = 0;
				break;
			case 100: //d
				if (msg.msg == key_msg_char)
					dx = speed;
				dy = 0;
				break;
			default:
				break;
			}
			rect.x += dx; rect.y += dy;
		}

		RectShow(rect);
		RectShow(rect_bk);
	}

	closegraph();
	return 0;
}
