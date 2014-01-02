
#include "../Classes/AppDelegate.h"
#include "cocos2d.h"
#include "HelloWorldScene.h"

USING_NS_CC;
const char* grp;
int main(int argc, char **argv)
{
	// create the application instance
    AppDelegate app;

	int width, height;
	const char *width_str, *height_str;
	width_str = getenv("WIDTH");
	height_str = getenv("HEIGHT");
	if (width_str && height_str)
	{
		width = atoi(width_str);
		height = atoi(height_str);
	}
	else
	{
		width = 1024;
		height = 600;
	}

    CCEGLView* eglView = CCEGLView::sharedOpenGLView();
    eglView->setFrameSize(width, height);


    HelloWorld *b=new HelloWorld();
   b->get_window_group_id(eglView->getWindowGroupId());

    return CCApplication::sharedApplication()->run();
}
