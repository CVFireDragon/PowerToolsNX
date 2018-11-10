#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <switch.h>

int main(int argc, char **argv)
{
	
    gfxInitDefault();
	consoleInit(NULL);
	printf("PowerToolsNX v0.2 - By CVFD\n");
	printf("Press A to shutdown or B to reboot");
	
	while(appletMainLoop())
    {
        hidScanInput();

        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
		if(kDown & KEY_B)
		{
        bpcInitialize();
        bpcRebootSystem();
		}
		
		if(kDown & KEY_A)
		{
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
