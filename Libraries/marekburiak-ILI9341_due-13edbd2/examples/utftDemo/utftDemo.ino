// UTFT Demo ported to ILI9341_due library by TFTLCDCyg

// Based on Demo 320x240 Serial of UTFT library 
// UTFT-web: http://www.henningkarlsen.com/electronics

#include <SPI.h>

// ILI9341_due NEW lib by Marek Buriak http://marekburiak.github.io/ILI9341_due/
#include "ILI9341_due_config.h"
#include "ILI9341_due.h"
#include "SystemFont5x7.h"
//#include "Streaming.h"
// For the Adafruit shield, these are the default.
#define TFT_RST 8
#define TFT_DC 9
#define TFT_CS 10
// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
ILI9341_due tft = ILI9341_due(TFT_CS, TFT_DC, TFT_RST);

char textBuff[20];

// Color set
#define	BLACK           0x0000
#define	RED             0xF800
#define	GREEN           0x07E0
//#define	BLUE            0x001F
#define	BLUE            0x102E
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0 
#define ORANGE          0xFD20
#define GREENYELLOW     0xAFE5 
#define DARKGREEN       0x03E0
#define WHITE           0xFFFF

uint16_t  color;
uint16_t  colorFONDO = BLACK;

void setup()
{
	randomSeed(analogRead(0));

	// TFT 2.2" SPI 
	Serial.begin(9600);
	tft.begin();
	tft.setRotation(iliRotation270);
	tft.fillScreen(colorFONDO);
	tft.setFont(SystemFont5x7);
}

void ILI9341duenodelay()
{
	int buf[318];
	int x, x2;
	int y, y2;
	int r;

	tft.fillScreen(colorFONDO);

	int timeinit = millis();


	//ILI9341due NEW
	tft.fillRect(0, 0, 320, 15, RED);
	tft.setTextColor(WHITE, RED);
	tft.printAlignedOffseted(F("* ILI9341_due UTFT 240x320 Demo *"), gTextAlignTopCenter, 0, 3);
	tft.fillRect(0, 226, 320, 240, tft.color565(64, 64, 64));
	tft.setTextColor(YELLOW, tft.color565(64, 64, 64));
	tft.printAlignedOffseted("<http://electronics.henningkarlsen.com>", gTextAlignBottomCenter, 0, -3);

	//ILI9341due NEW
	tft.drawRect(0, 15, 320, 211, BLUE);

	//ILI9341due NEW
	// Draw crosshairs
	tft.drawLine(159, 15, 159, 224, BLUE);
	tft.drawLine(1, 119, 318, 119, BLUE);
	for (int i = 9; i < 310; i += 10)
		tft.drawLine(i, 117, i, 121, BLUE);
	for (int i = 19; i < 220; i += 10)
		tft.drawLine(157, i, 161, i, BLUE);
	// Draw sin-, cos- and tan-lines  
	tft.setTextColor(CYAN, BLACK);
	tft.printAt("Sin", 5, 17);
	for (int i = 1; i < 318; i++)
	{
		tft.drawPixel(i, 119 + (sin(((i*1.13)*3.14) / 180) * 95), CYAN);
	}
	tft.setTextColor(RED, BLACK);
	tft.printAt("Cos", 5, 29);
	for (int i = 1; i < 318; i++)
	{
		tft.drawPixel(i, 119 + (cos(((i*1.13)*3.14) / 180) * 95), RED);
	}
	tft.setTextColor(YELLOW, BLACK);
	tft.printAt("Tan", 5, 41);
	for (int i = 1; i < 318; i++)
	{
		tft.drawPixel(i, 119 + (tan(((i*1.13)*3.14) / 180)), YELLOW);
	}
	//delay(2000);


	//ILI9341due NEW
	tft.fillRect(1, 16, 318, 209, BLACK);
	tft.drawLine(159, 16, 159, 224, BLUE);
	tft.drawLine(1, 119, 318, 119, BLUE);

	// Draw a moving sinewave
	x = 1;
	for (int i = 1; i < (318 * 20); i++)
	{
		x++;
		if (x == 319)
			x = 1;
		if (i > 319)
		{
			if ((x == 159) || (buf[x - 1] == 119))
				color = BLUE;
			else
				color = BLACK;
			tft.drawPixel(x, buf[x - 1], color);
		}
		y = 119 + (sin(((i*1.1)*3.14) / 180)*(90 - (i / 100)));
		tft.drawPixel(x, y, CYAN);
		buf[x - 1] = y;
	}
	//delay(2000);


	//ILI9341due NEW
	tft.fillRect(1, 16, 318, 209, BLACK);

	// Draw some filled rectangles
	for (int i = 1; i < 6; i++)
	{
		switch (i)
		{
		case 1:
			color = MAGENTA;
			break;
		case 2:
			color = RED;
			break;
		case 3:
			color = GREEN;
			break;
		case 4:
			color = BLUE;
			break;
		case 5:
			color = YELLOW;
			break;
		}
		tft.fillRect(70 + (i * 20), 30 + (i * 20), 60, 60, color);
	}
	//delay(2000);


	//ILI9341due NEW
	tft.fillRect(1, 16, 318, 209, BLACK);

	// Draw some filled, rounded rectangles
	for (int i = 1; i < 6; i++)
	{
		switch (i)
		{
		case 1:
			color = MAGENTA;
			break;
		case 2:
			color = RED;
			break;
		case 3:
			color = GREEN;
			break;
		case 4:
			color = BLUE;
			break;
		case 5:
			color = YELLOW;
			break;
		}
		tft.fillRoundRect(190 - (i * 20), 30 + (i * 20), 60, 60, 3, color);
	}
	//delay(2000);


	//ILI9341due NEW
	tft.fillRect(1, 16, 318, 209, BLACK);

	// Draw some filled circles
	for (int i = 1; i < 6; i++)
	{
		switch (i)
		{
		case 1:
			color = MAGENTA;
			break;
		case 2:
			color = RED;
			break;
		case 3:
			color = GREEN;
			break;
		case 4:
			color = BLUE;
			break;
		case 5:
			color = YELLOW;
			break;
		}
		tft.fillCircle(100 + (i * 20), 60 + (i * 20), 30, color);
	}
	//delay(2000);


	//ILI9341due NEW
	tft.fillRect(1, 16, 318, 209, BLACK);

	// Draw some lines in a pattern
	for (int i = 17; i < 222; i += 5)
	{
		tft.drawLine(1, i, (i*1.44) - 10, 224, RED);
	}
	for (int i = 222; i > 17; i -= 5)
	{
		tft.drawLine(318, i, (i*1.44) - 11, 17, RED);
	}
	for (int i = 222; i > 17; i -= 5)
	{
		tft.drawLine(1, i, 331 - (i*1.44), 17, CYAN);
	}
	for (int i = 17; i < 222; i += 5)
	{
		tft.drawLine(318, i, 330 - (i*1.44), 223, CYAN);
	}
	//delay(2000);


	//ILI9341due NEW
	tft.fillRect(1, 16, 318, 209, BLACK);

	// Draw some random circles
	for (int i = 0; i < 100; i++)
	{
		color = tft.color565(random(255), random(255), random(255));
		x = 32 + random(256);
		y = 45 + random(146);
		r = random(30);
		tft.drawCircle(x, y, r, color);
	}
	//delay(2000);


	//ILI9341due NEW
	tft.fillRect(1, 16, 318, 209, BLACK);

	// Draw some random rectangles
	for (int i = 0; i < 100; i++)
	{
		color = tft.color565(random(255), random(255), random(255));
		x = random(316);
		y = random(207);
		x2 = random(316 - x);
		y2 = random(207 - y);
		tft.drawRect(2 + x, 16 + y, x2, y2, color);
	}
	//delay(2000);


	//ILI9341due NEW
	tft.fillRect(1, 16, 318, 209, BLACK);

	// Draw some random rounded rectangles
	for (int i = 0; i < 100; i++)
	{
		color = tft.color565(random(255), random(255), random(255));
		x = random(310);
		y = random(201);
		x2 = random(310 - x);
		y2 = random(201 - y);
		tft.drawRoundRect(2 + x, 16 + y, x2 + 6, y2 + 6, 3, color);
	}
	//delay(2000);

	//ILI9341due NEW
	tft.fillRect(1, 16, 318, 209, BLACK);

	for (int i = 0; i < 100; i++)
	{
		color = tft.color565(random(255), random(255), random(255));
		x = 2 + random(316);
		y = 16 + random(209);
		x2 = 2 + random(316);
		y2 = 16 + random(209);
		tft.drawLine(x, y, x2, y2, color);
	}
	//delay(2000);


	//ILI9341due NEW
	tft.fillRect(1, 16, 318, 209, BLACK);

	for (int i = 0; i < 10000; i++)
	{
		color = tft.color565(random(255), random(255), random(255));
		tft.drawPixel(2 + random(316), 16 + random(209), color);
	}
	int timetest = millis() - timeinit;
	//delay(2000);


	//ILI9341due NEW
	tft.fillRect(0, 0, 320, 240, BLUE);
	tft.fillRoundRect(80, 70, 159, 99, 3, RED);
	tft.setTextColor(WHITE, RED);
	tft.printAt("That's it!", 130, 93);
	tft.printAt("Restarting in a", 112, 119);
	tft.printAt("few seconds...", 117, 132);

	tft.setTextColor(WHITE, BLUE);
	tft.printAt("Runtime: (msecs)", 112, 210);

	sprintf(textBuff, "%d", timetest);
	tft.printAt(textBuff, 146, 225);
}

void loop()
{
	ILI9341duenodelay();
	delay(5000);
}

