#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <switch.h>

int main(int argc, char **argv)
{
	
    gfxInitDefault();
	consoleInit(NULL);
	printf("PowerToolsNX v0.2 - By CVFD\n");
	printf("Press A to shutdown, B to reboot");
	printf("or X to reboot into RCM (DO NOT USE ON EXFAT)");
	
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
		
		if(kDown & KEY_X)
		{
        Result rc = splInitialize();
		rc = splSetConfig ((SplConfigItem) 65001, 1);
			
		}
		
        if (kDown & KEY_PLUS) break;
		
        gfxFlushBuffers();
        gfxSwapBuffers();
        gfxWaitForVsync();
    }

    consoleExit(NULL);		
    gfxExit();
    return 0;
}
