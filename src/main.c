#include <string.h>
#include <stdio.h>

#include <switch.h>

int main(int argc, char **argv)
{
    gfxInitDefault();

    printf("Press A to Shutdown or B to Reboot");
	while(appletMainLoop())
    {
        hidScanInput();

        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
		if(kDown & KEY_B)
		{
    consoleInit(NULL);
    bpcInitialize();
    bpcRebootSystem();
		}
		
		if(kDown & KEY_A)
		{
    consoleInit(NULL);
    bpcInitialize();
    bpcShutdownSystem();
		}
		
        if (kDown & KEY_PLUS) break;
		
        gfxFlushBuffers();
        gfxSwapBuffers();
        gfxWaitForVsync();
    }

    gfxExit();
    return 0;
}
