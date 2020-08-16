
										#include "CAnimal.h"
										#include "Console.h"
										#include <thread>

										void background()
										{
											PlaySound(TEXT("a.wav"), NULL,SND_LOOP | SND_ASYNC);
	
										}

										void init()
										{
											for (int i = 0; i <= HEIGHT ; i++)
												for (int j = 0; j <= WIDTH; j++)
													buffer.square(i, j, ' ');
										}
										void display(CBIRD b, CDINOSAUR d)
										{
											//Draw background
											for (int i = 0; i <= HEIGHT; i++)
												for (int j = 0; j < WIDTH; j++)
												{
													if (i == 0 && j == WIDTH - 1) buffer.square(i, j, (char)187);
													else if (i % 5 == 0)
													{
														if (j == WIDTH - 1) buffer.square(i, j, (char)185);
														else buffer.square(i, j, (char)205);
													}
													else if (j == WIDTH - 1)
													 buffer.square(i, j, (char)186);
												}
											//Draw Bird
											b.Move(9);
											//Draw Dinosaur
											d.Move(10);

											GotoXY(0, 0);
											for (int i = 0; i < HEIGHT; i++)
											{
												for (int j = 0; j < WIDTH; j++)
												{
													TextColor(buffer.table[i][j].color);
													putchar(buffer.table[i][j].character);
													buffer.table[i][j].character = ' ';
												}
												if (i < HEIGHT - 1)
													putchar('\n');
											}

										}

										void handle(CBIRD& b, CDINOSAUR& d)
										{
											b.goRight();
											if (b.getX() == WIDTH - lengthB) b.Update(1, 11);
											d.goRight();
											if (d.getX() == WIDTH - lengthD) d.Update(1, 21);
										}
										int main()
										{
											FixConsoleWindow();
											ShowCur(0);
											DisableSelection();
											ShowScrollBar(GetConsoleWindow(), SB_BOTH, 0);
											system("title Game");
											init();
											CBIRD b;
											CDINOSAUR d;
											while (1)
											{
												display(b, d);
												handle(b, d);
												Sleep(5);
											}

											/*HANDLE h = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)printB, NULL, NULL,NULL);
											HANDLE h1 = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)printD, NULL, NULL, NULL);
											WaitForSingleObject(h, INFINITE);
											CloseHandle(h);
											WaitForSingleObject(h1, INFINITE);
											CloseHandle(h1);*/
											/*thread Bird(t1);
											thread Dinosaur(t2);
											if (Bird.joinable()) Bird.join();
											if (Dinosaur.joinable()) Dinosaur.join();*/
											/*thread b(background);
											thread Bird(printB);
											thread Dinosaur(printD);
											Bird.join();
											Dinosaur.join();
											b.join();*/
											//CDINOSAUR d;
											//d.Tell();
											//background();

											/*thread dino(&CDINOSAUR::Tell,d);
											dino.join();
											*/

											return 0;
										}