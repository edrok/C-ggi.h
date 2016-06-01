#include <stdio.h>
#include <stdlib.h>
#include <ggi/ggi.h>

ggi_visual_t vis;
ggi_mode mode;
char s[25];
int i=35,t,x,y;
//char c='O';
ggi_color clr={0xFFFF,0xFFFF,0xFFFF,0};
ggi_color clr1={0x0000,0x0000,0x0000,0};
int main() {
	printf("Enter creeping line:\n");
	gets(s);

  if (ggiInit()) {
    fprintf(stderr,"ggiInit failed\n");
    exit(1);
  }
  vis=ggiOpen(NULL);
  if (!vis) ggiPanic("ggiOpen failed");
  ggiSetFlags(vis,GGIFLAG_ASYNC);
  ggiParseMode("",&mode);
  ggiSetMode(vis,&mode);
  //ggiSPrintMode(s,&mode);
  //ggiSetGCForeground(vis,ggiMapColor(vis,&clr));
  //ggiPuts(vis,300,300,s);

  while (!ggiKbhit(vis)) {

	for (i=1;i<1150;i++) {
	for(t=0; t<7000000; t++) ;	
  	ggiSetGCForeground(vis,ggiMapColor(vis,&clr));
  	ggiPuts(vis,i,300,s); 
	ggiGetCharSize(vis, &x,&y );
  	ggiSetGCForeground(vis,ggiMapColor(vis,&clr1));
  	ggiDrawBox(vis, i-x, 300, x, y);
	if (i==1149){
	ggiSetGCForeground(vis,ggiMapColor(vis,&clr1));
  	ggiDrawBox(vis, i, 300, 100, 14);}
	}
			}
  ggiClose(vis);
  ggiExit();
}

