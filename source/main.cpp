#include <stdio.h>
#include <nds.h>

volatile int frame = 0;
void vBlank(){
    frame++;
}
int main(void) {
    consoleDemoInit();
    irqSet(IRQ_VBLANK, vBlank);
    iprintf("Hello World! \n Soon, this will be Helicopter Dash!");
while(1){
    iprintf("\x1b[10;0HFrame = %d",frame);
    swiWaitForVBlank();
}
    return 0;
}