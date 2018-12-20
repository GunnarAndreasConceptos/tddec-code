#ifndef D_MyLightController_H
#define D_MyLightController_H

enum{MAX_LIGHTS = 32};

void MyLightController_Create(void);
void MyLightController_Destroy(void);
void MyLightController_On(int);
void MyLightController_Off(int);

#endif  /* D_MyLightController_H */
