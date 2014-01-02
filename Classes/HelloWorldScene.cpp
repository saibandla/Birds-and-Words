#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "string.h"

#include <bps/bps.h>
#include <bps/paymentservice.h>
#include <bps/navigator.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "CCEGLView.h"
#include <bps/screen.h>

static screen_context_t screen_ctx;
static screen_window_t screen_win;
USING_NS_CC;
using namespace CocosDenshion;
int xcount[20];
std::vector<int> arr;
int reveallast=0;
char st[12];
int birdtag;
int levels=0,levelnos,unlocking=0;
CCMenuItemImage *pCloseItem;
const char * groupid;
int levelicon1=0,levelicon2=0,levelicon3=0,levelicon4=0,levelicon5=0,levelicon6=0,levelicon7=0,levelicon8=0,levelicon9=0,levelicon10=0,levelicon11=0,levelicon12=0,levelicon13=0,levelicon14=0,levelicon15=0,levelicon16=0,levelicon17=0,levelicon18=0,levelicon19=0,levelicon20=0,levelicon21=0,levelicon22=0,levelicon23=0,levelicon24=0,levelicon25=0,levelicon26=0,levelicon27=0,levelicon28=0,levelicon29=0,levelicon30=0,levelicon31=0,levelicon32=0,levelicon33=0,levelicon34=0,levelicon35=0,levelicon36=0,levelicon37=0,levelicon38=0,levelicon39=0,levelicon40=0,levelicon41=0,levelicon42=0,levelicon43=0,levelicon44=0,levelicon45=0,levelicon46=0,levelicon47=0,levelicon48=0,levelicon49=0,levelicon50=0,levelicon51=0,levelicon52=0,levelicon53=0,levelicon54=0,levelicon55=0,levelicon56=0,levelicon57=0,levelicon58=0,levelicon59=0,levelicon60=0,levelicon61=0,levelicon62=0,levelicon63=0,levelicon64=0,levelicon65=0,levelicon66=0,levelicon67=0,levelicon68=0,levelicon69=0,levelicon70=0,levelicon71=0,levelicon72=0,levelicon73=0,levelicon74=0,levelicon75=0;
int levelpack2unclock=0,levelpack3unclock=0;
int progress1cnt=0,progress2cnt=0,progress3cnt=0;
//int HelloWorld::setup_screen()
//{
//	fprintf(stderr,"hack1");
//	if (screen_create_context(&screen_ctx, SCREEN_APPLICATION_CONTEXT) != 0) {
//	        return EXIT_FAILURE;
//	    }
//	fprintf(stderr,"hack2");
//	if (screen_create_window(&screen_win, screen_ctx) != 0) {
//	        screen_destroy_context(screen_ctx);
//	        return EXIT_FAILURE;
//	    }
//	fprintf(stderr,"hack3");
//	if (screen_create_window_group(screen_win,groupid) != 0){
//	        return EXIT_FAILURE;
//	    }
//	fprintf(stderr,"hack4");
//	int usage = SCREEN_USAGE_NATIVE;
//
//	    if (screen_set_window_property_iv(screen_win, SCREEN_PROPERTY_USAGE, &usage) != 0) return EXIT_FAILURE;
//	    fprintf(stderr,"hack5");
//	if (screen_create_window_buffers(screen_win, 1) != 0) return EXIT_FAILURE;
//	screen_buffer_t buff;
//	fprintf(stderr,"hack6");
//	    if (screen_get_window_property_pv(screen_win, SCREEN_PROPERTY_RENDER_BUFFERS, (void**)&buff) != 0) return EXIT_FAILURE;
//	int buffer_size[2];
//	fprintf(stderr,"hack7");
//	    if (screen_get_buffer_property_iv(buff, SCREEN_PROPERTY_BUFFER_SIZE, buffer_size) != 0) return EXIT_FAILURE;
//	int attribs[1] = {SCREEN_BLIT_END};
//	fprintf(stderr,"hack8");
//	    if (screen_fill(screen_ctx, buff, attribs) != 0) return EXIT_FAILURE;
//	int dirty_rects[4] = {0, 0, buffer_size[0], buffer_size[1]};
//	fprintf(stderr,"hack9");
//	    if (screen_post_window(screen_win, buff, 1, (const int*)dirty_rects, 0) != 0) return EXIT_FAILURE;
//	return EXIT_SUCCESS;
//
//
//
//
//}
//static const char *get_window_group_id()
//{
//    static char s_window_group_id[16] = "";
//
//    if (s_window_group_id[0] == '\0') {
//        snprintf(s_window_group_id, sizeof(s_window_group_id), "%d", getpid());
//    }
//
//    return s_window_group_id;
//}

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object

    CCScene *scene = CCScene::create();

    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}
int count=0;
int scal=0;
float x[10],y[10];
CCPoint orginal;
int lastval=0;
int one=0,two=0,three=0,four=0,five=0,six=0,seven=0,eight=0,coinscnt=300,index1=0,capacityy=0;
CCSprite *solutionback;
const char *att[5];
CCMenuItemImage *lastimg;
CCLabelTTF *lastletter;
CCLabelTTF *level1prg,*level2prg,*level3prg,*labelcoincnt;
// on "init" you need to initialize your instance
CCSize size;
CCPointArray *points;
CCArray *input;
CCProgressTimer *progrress,*progrress2,*progrress3;
const char* digital_good_id="29856901";
   const char* digital_good_name= "750 coins";
   const char* digital_good_sku ="pack1_wordgame";
   const char* metadata="simple";
   const char* purchase_app_icon = "http://www.rim.com/products/appworld_3col.jpg";
   const char* purchase_app_name = "Payment Service Sample App";

       /*
        * Define a request ID to hold the returned value from the purchase request.
        */
       unsigned request_id = 0;
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    bps_initialize();
//    if (HelloWorld::setup_screen() != EXIT_SUCCESS) {
//           fprintf(stderr, "Unable to initialize screen.");
//           exit(0);
//       }
   // navigator_request_events(0);
       paymentservice_request_events(0);
//       bps_event_t *event = NULL;
//             bps_get_event(&event, -1);

       /*
        * Set the Payment Service connection mode to local. This allows us to
        * test the API without the need to contact the AppWorld nor payment servers.
        */
       paymentservice_set_connection_mode(false);

       /*
        * Create a set of purchase parameters, which describe the digital good
        * to be purchased and the applicpurchase_app_nameation the goods are associated with.
        */

	 size = CCDirector::sharedDirector()->getWinSize();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
//	 CCSprite *splash=CCSprite::create("Default-568h@2x.png");
//	 splash->setPosition(ccp(size.width/2,size.height/2));
//	 this->addChild(splash);
//	 this->runAction(CCSequence::create(CCDelayTime::create(2.0),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::mainscene)),NULL));
    HelloWorld::mainscene();

    HelloWorld::levelpc1();


    return true;
}
void HelloWorld::sched()
{
	bps_event_t *event = NULL;
	        bps_get_event(&event, -1);

	        if (event) {

	            /*
	             * If it is a Payment Service event, determine the response code
	             * and handle the event accordingly.
	             */
//	        	if(bps_event_get_domain(event)==screen_get_domain())
//	        		            {
//
//	        		            }
	            if (bps_event_get_domain(event) == paymentservice_get_domain()) {
	            	fprintf(stderr,"hacked by bharga");
	                if (SUCCESS_RESPONSE == paymentservice_event_get_response_code(event)) {
	                    if (PURCHASE_RESPONSE == bps_event_get_code(event)) {
	                    	fprintf(stderr,"hai bhargav1");
	                        HelloWorld::onPurchaseSuccess(event);
	                        fprintf(stderr,"bye bhargav1");
	                        unsigned request_id = 0;
	                        if (paymentservice_get_existing_purchases_request(false, groupid, &request_id) != BPS_SUCCESS) {
	                            fprintf(stderr, "Error: get existing purchases failed.\n");
	                        }
	                    } else
	                        HelloWorld::onGetExistingPurchasesSuccess(event);
	                } else {
	                    HelloWorld::failureCommon(event);
	                }
	            }





}
}
void HelloWorld::mutesound()
{
	CCSprite *off=CCSprite::create("sound-off@2x.png");
	CCSprite *on=CCSprite::create("sound-on@2x.png");
	if(SimpleAudioEngine::sharedEngine()->getBackgroundMusicVolume()>0.0||SimpleAudioEngine::sharedEngine()->getEffectsVolume()>0.0)
	{

		pCloseItem->setNormalImage(off);
						pCloseItem->setSelectedImage(off);
	SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.0f);
		SimpleAudioEngine::sharedEngine()->setEffectsVolume(0.0f);
	}
	else
	{
		pCloseItem->setNormalImage(on);
				pCloseItem->setSelectedImage(on);

		SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.4f);
				SimpleAudioEngine::sharedEngine()->setEffectsVolume(1.0f);

	}
}
void HelloWorld::mainscene()
{
	this->removeAllChildren();
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("bgmusic.wav",true);
	SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.7);
	 size = CCDirector::sharedDirector()->getWinSize();
	pCloseItem = CCMenuItemImage::create(
	                                        "sound-on@2x.png",
	                                        "sound-on@2x.png",
	                                        this,
	                                        menu_selector(HelloWorld::mutesound));


	    pCloseItem->setPosition(ccp(size.width - 50, size.height-70));
	    CCLabelTTF *title=CCLabelTTF::create("Birds and Words","Arial",35.0f);
	    title->setPosition(ccp(size.width/2,size.height-70));
	    this->addChild(title,3);

	    HelloWorld::addbackground();
	    CCSprite *norm=CCSprite::create("bg_menu_box@2x.png");
	    CCMenuItemImage *level1 = CCMenuItemImage::create("bg_menu_box@2x.png","bg_menu_box@2x.png",this,menu_selector(HelloWorld::level1pack));
	    level1->setPosition(ccp(384,title->getPosition().y-350));
	    this->addChild(level1,2);
	    CCSprite *progress1=CCSprite::create("progress_track@2x.png");
	    progress1->setPosition(ccp(level1->getPosition().x,level1->getPosition().y-30));
	    this->addChild(progress1,3);
	    CCSprite *progress12=CCSprite::create("progress_image@2x.png");

	    progrress=CCProgressTimer::create(progress12);
	   // progrress->setSprite(progress12);
	    progrress->setType(kCCProgressTimerTypeBar);
	    //progrress->setAnchorPoint(ccp(0,0));
	    progrress->setBarChangeRate(ccp(1,0));
	    if(progress1cnt<=25)
	    {
	    progrress->setPercentage(4.0*progress1cnt);
	    }
	    progrress->setPosition(progress1->getPosition());
	    //progrress->setContentSize(CCSize(0,progress1->getContentSize().height));
	    progrress->setMidpoint(ccp(0,0));
	    progrress->updateBar();
	    this->addChild(progrress,4);

//	    	    progress1->setPosition(ccp(level1->getPosition().x,level1->getPosition().y-30));
//	    	    this->addChild(progress1,3);
	    level1prg=CCLabelTTF::create("0%","Arial",35.0f);
	    level1prg->setPosition(ccp(size.width/2,level1->getPosition().y-30));
	    char prglevel[4];

	    sprintf(prglevel,"%d%c",(4*progress1cnt),'%');
	   // prglevel[3]='%';
	    level1prg->setString(prglevel);
	    this->addChild(level1prg,5);
	    CCLabelTTF *label1=CCLabelTTF::create("Level Pack1","Arial",35.0f);
	    label1->setColor(ccc3(72,61,139));
	    label1->setPosition(ccp(level1->getPosition().x,level1->getPosition().y+50));
	    this->addChild(label1,4);

	    CCMenuItemImage *level2;


	    	level2=CCMenuItemImage::create("bg_menu_box_locked@2x.png","bg_menu_box_locked@2x.png",this,menu_selector(HelloWorld::level2pack));
	    	level2->setPosition(ccp(size.width/2,level1->getPosition().y-level1->getContentSize().height/2-100));
	    	if(levelpack2unclock==1)
	    	{
	    		level2->setNormalImage(norm);
	    		level2->setSelectedImage(norm);
	    	}
	    	CCSprite *progress2=CCSprite::create("progress_track@2x.png");
	    	progress2->setPosition(ccp(level2->getPosition().x,level2->getPosition().y-30));
	    	this->addChild(progress2,3);
	    	CCSprite *progress124=CCSprite::create("progress_image@2x.png");
	    	progrress2=CCProgressTimer::create(progress124);
	    	progrress2->setType(kCCProgressTimerTypeBar);
	    	progrress2->setBarChangeRate(ccp(1,0));
	    	if(progress2cnt<=25)
	    	{
	    		progrress2->setPercentage(4.0*progress2cnt);
	    	}
	    	progrress2->setPosition(progress2->getPosition());
	    	progrress2->setMidpoint(ccp(0,0));
	    	progrress2->updateBar();
	    	this->addChild(progrress2,4);
	    	level2prg=CCLabelTTF::create("0%","Arial",35.0f);
	    	level2prg->setPosition(ccp(size.width/2,level2->getPosition().y-30));
	    	char prglevel1[4];
	    	sprintf(prglevel1,"%d%c",(4*progress2cnt),'%');
	    	level2prg->setString(prglevel1);
	    	this->addChild(level2prg,4);
	    	CCLabelTTF *label2=CCLabelTTF::create("Level Pack2","Arial",35.0f);
	    	label2->setColor(ccc3(72,61,139));
	    	label2->setPosition(ccp(level2->getPosition().x,level2->getPosition().y+50));
	    	this->addChild(label2,4);
	    CCMenuItemImage *level3;

	    	level3=CCMenuItemImage::create("bg_menu_box_locked@2x.png","bg_menu_box_locked@2x.png",this,menu_selector(HelloWorld::level3pack));
	        level3->setPosition(ccp(size.width/2,level2->getPosition().y-level2->getContentSize().height/2-100));
	        if(levelpack3unclock==1)
	        {
	        	level3->setNormalImage(norm);
	            level3->setSelectedImage(norm);
	        }
	        CCSprite *progress3=CCSprite::create("progress_track@2x.png");
	        progress3->setPosition(ccp(level3->getPosition().x,level3->getPosition().y-30));
	        this->addChild(progress3,3);
	        CCSprite *progress125=CCSprite::create("progress_image@2x.png");
	        progrress3=CCProgressTimer::create(progress125);
	        progrress3->setType(kCCProgressTimerTypeBar);
	        progrress3->setBarChangeRate(ccp(1,0));
	        if(progress3cnt<=25)
	        {
	        	progrress3->setPercentage(4.0*progress3cnt);
	        }
	        progrress3->setPosition(progress3->getPosition());
	        progrress3->setMidpoint(ccp(0,0));
	        progrress3->updateBar();
	        level3prg=CCLabelTTF::create("0%","Arial",35.0f);
	        level3prg->setPosition(ccp(size.width/2,level3->getPosition().y-30));
	        char prglevel3[4];
	        sprintf(prglevel3,"%d%c",(4*progress2cnt),'%');
	        level2prg->setString(prglevel3);
	        this->addChild(level3prg,4);
	        CCLabelTTF *label3=CCLabelTTF::create("Level Pack3","Arial",35.0f);
	        label3->setColor(ccc3(72,61,139));
	        label3->setPosition(ccp(level3->getPosition().x,level3->getPosition().y+50));
	        this->addChild(label3,4);

	        CCMenu* pMenu = CCMenu::create(pCloseItem,level1,level2,level3,NULL);
	        pMenu->setPosition(CCPointZero);
	        this->addChild(pMenu, 1);
	        this->schedule(schedule_selector(HelloWorld::updt));
}
struct level1
{
	std::string ans;
	std::string other;
	char quer[12];

};
struct level1 query[75];
void HelloWorld::addbackground()
{
	 CCSprite* pSprite = CCSprite::create("homescreen.jpg");
	 pSprite->setPosition( ccp(size.width/2, size.height/2) );
	 this->addChild(pSprite, -1);
}
void HelloWorld::level1pack()
{
	if(unlocking==0)
	{
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	CCSize windowSize=CCDirector::sharedDirector()->getWinSize();
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	CCMenuItemImage *back_button1=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button1-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button1->getContentSize().width-back_button1->getContentSize().width,visibleSize.height/2+origin.y+20+back_button1->getContentSize().height+back_button1->getContentSize().height+10));
	back_button1->setTag(401);

	CCMenuItemImage *back_button2=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button2-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button2->getContentSize().width,visibleSize.height/2+origin.y+20+back_button2->getContentSize().height+back_button2->getContentSize().height));
	back_button2->setTag(402);

	CCMenuItemImage *back_button3=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button3-> setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20+back_button3->getContentSize().height+back_button3->getContentSize().height));
	back_button3->setTag(403);

	CCMenuItemImage *back_button4=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button4-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button4->getContentSize().width,visibleSize.height/2+origin.y+20+back_button4->getContentSize().height+back_button4->getContentSize().height));
	back_button4->setTag(404);

	CCMenuItemImage *back_button5=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button5-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button4->getContentSize().width+back_button4->getContentSize().width,visibleSize.height/2+origin.y+20+back_button4->getContentSize().height+back_button4->getContentSize().height));
	back_button5->setTag(405);

	CCMenuItemImage *back_button6=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button6-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button6->getContentSize().width-back_button6->getContentSize().width,visibleSize.height/2+origin.y+20+back_button6->getContentSize().height));
	back_button6->setTag(406);

	CCMenuItemImage *back_button7=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button7-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button7->getContentSize().width,visibleSize.height/2+origin.y+20+back_button7->getContentSize().height));
	back_button7->setTag(407);

	CCMenuItemImage *back_button8=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button8-> setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20+back_button8->getContentSize().height));
	back_button8->setTag(408);

	CCMenuItemImage *back_button9=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button9-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button9->getContentSize().width,visibleSize.height/2+origin.y+20+back_button9->getContentSize().height));
	back_button9->setTag(409);

	CCMenuItemImage *back_button10=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button10-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button10->getContentSize().width+back_button10->getContentSize().width,visibleSize.height/2+origin.y+20+back_button10->getContentSize().height));
	back_button10->setTag(410);

	CCMenuItemImage *back_button11=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button11-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button11->getContentSize().width-back_button11->getContentSize().width,visibleSize.height/2+origin.y+20));
	back_button11->setTag(411);

	CCMenuItemImage *back_button12=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button12-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button12->getContentSize().width,visibleSize.height/2+origin.y+20));
	back_button12->setTag(412);

	CCMenuItemImage *back_button13=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button13-> setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20));
	back_button13->setTag(413);

	CCMenuItemImage *back_button14=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button14-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button12->getContentSize().width,visibleSize.height/2+origin.y+20));
	back_button14->setTag(414);

	CCMenuItemImage *back_button15=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button15-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button12->getContentSize().width+back_button12->getContentSize().width,visibleSize.height/2+origin.y+20));
	back_button15->setTag(415);

	CCMenuItemImage *back_button16=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button16-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button16->getContentSize().width-back_button1->getContentSize().width,visibleSize.height/2+origin.y+20-back_button16->getContentSize().height));
	back_button16->setTag(416);

	CCMenuItemImage *back_button17=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button17-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button17->getContentSize().width,visibleSize.height/2+origin.y+20-back_button17->getContentSize().height));
	back_button17->setTag(417);

	CCMenuItemImage *back_button18=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button18-> setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20-back_button18->getContentSize().height));
	back_button18->setTag(418);

	CCMenuItemImage *back_button19=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button19-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button19->getContentSize().width,visibleSize.height/2+origin.y+20-back_button19->getContentSize().height));
	back_button19->setTag(419);

	CCMenuItemImage *back_button20=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button20-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button20->getContentSize().width+back_button20->getContentSize().width,visibleSize.height/2+origin.y+20-back_button20->getContentSize().height));
	back_button20->setTag(420);

	CCMenuItemImage *back_button21=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button21-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button21->getContentSize().width-back_button21->getContentSize().width,visibleSize.height/2+origin.y+20-back_button21->getContentSize().height-back_button21->getContentSize().height));
	back_button21->setTag(421);

	CCMenuItemImage *back_button22=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button22-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button22->getContentSize().width,visibleSize.height/2+origin.y+20-back_button22->getContentSize().height-back_button22->getContentSize().height));
	back_button22->setTag(422);

	CCMenuItemImage *back_button23=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button23-> setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20-back_button23->getContentSize().height-back_button23->getContentSize().height));
	back_button23->setTag(423);

	CCMenuItemImage *back_button24=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button24-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button24->getContentSize().width,visibleSize.height/2+origin.y+20-back_button24->getContentSize().height-back_button24->getContentSize().height));
	back_button24->setTag(424);

	CCMenuItemImage *back_button25=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button25-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button25->getContentSize().width+back_button25->getContentSize().width,visibleSize.height/2+origin.y+20-back_button25->getContentSize().height-back_button25->getContentSize().height));
	back_button25->setTag(425);

	this->removeAllChildren();
	HelloWorld::addbackground();
	CCSprite *imj=CCSprite::create("bg_level_completed@2x.png");
	CCSprite *imj1=CCSprite::create("bg_level@2x.png");

	CCLabelTTF* select_level=CCLabelTTF::create("Select Level","Arial",35);
	select_level->setPosition(ccp(windowSize.width-375,windowSize.height-40));
	this->addChild(select_level,1);

	CCMenuItemImage *back_button=CCMenuItemImage::create("back@2x.png","back@2x.png",this,menu_selector(HelloWorld::mainscene));
	back_button-> setPosition(ccp(40,windowSize.height-55));

	//levels
if(levelicon1 == 1)
	{
		back_button1->setNormalImage(imj);
    }
if(levelicon2 == 1)
	{
		back_button2->setNormalImage(imj);
	}
 if(levelicon3 == 1)
	{
	 back_button3->setNormalImage(imj);
	}
if(levelicon4 == 1)
	{
	back_button4->setNormalImage(imj);
	}

if(levelicon5 == 1)
	{
	back_button5->setNormalImage(imj);
	}

if(levelicon6 == 1)
	{
	back_button6->setNormalImage(imj);
	}

if(levelicon7 == 1)
	{
	back_button7->setNormalImage(imj);
	}

if(levelicon8 == 1)
	{
	back_button8->setNormalImage(imj);
	}

if(levelicon9 == 1)
	{
	back_button9->setNormalImage(imj);
	}

if(levelicon10 == 1)
	{
	back_button10->setNormalImage(imj);
	}
if(levelicon11 == 1)
	{
	back_button11->setNormalImage(imj);
	}
if(levelicon12 == 1)
	{
	back_button12->setNormalImage(imj);
	}
if(levelicon13 == 1)
	{
	back_button13->setNormalImage(imj);
	}
if(levelicon14 == 1)
    {
	back_button14->setNormalImage(imj);
    }
if(levelicon15 == 1)
	{
	back_button15->setNormalImage(imj);
	}
if(levelicon16 == 1)
	{
	back_button16->setNormalImage(imj);
	}

if(levelicon17 == 1)
	{
	back_button17->setNormalImage(imj);
	}

if(levelicon18 == 1)
	{
	back_button18->setNormalImage(imj);
	}

if(levelicon19 == 1)
	{
	back_button19->setNormalImage(imj);
	}
if(levelicon20 == 1)
	{
	back_button20->setNormalImage(imj);
	}
if(levelicon21 == 1)
	{
	back_button21->setNormalImage(imj);
	}
if(levelicon22 == 1)
	{
	back_button22->setNormalImage(imj);
	}

if(levelicon23 == 1)
	{
	back_button23->setNormalImage(imj);
	}

if(levelicon24 == 1)
	{
	back_button24->setNormalImage(imj);
	}

if(levelicon25 == 1)
	{
	back_button25->setNormalImage(imj);
	}

CCLabelTTF* num1=CCLabelTTF::create("1","Arial",35);
	num1->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button1->getContentSize().width-back_button1->getContentSize().width,visibleSize.height/2+origin.y+20+back_button1->getContentSize().height+back_button1->getContentSize().height+10));
	this->addChild(num1,3);
CCLabelTTF* num2=CCLabelTTF::create("2","Arial",35);
	num2->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button2->getContentSize().width,visibleSize.height/2+origin.y+20+back_button2->getContentSize().height+back_button2->getContentSize().height));
	this->addChild(num2,3);
CCLabelTTF* num3=CCLabelTTF::create("3","Arial",35);
	num3->setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20+back_button3->getContentSize().height+back_button3->getContentSize().height));
	this->addChild(num3,3);
CCLabelTTF* num4=CCLabelTTF::create("4","Arial",35);
	num4->setPosition(ccp(10+origin.x+visibleSize.width/2+back_button4->getContentSize().width,visibleSize.height/2+origin.y+20+back_button4->getContentSize().height+back_button4->getContentSize().height));
	this->addChild(num4,3);
CCLabelTTF* num5=CCLabelTTF::create("5","Arial",35);
	num5->setPosition(ccp(10+origin.x+visibleSize.width/2+back_button4->getContentSize().width+back_button4->getContentSize().width,visibleSize.height/2+origin.y+20+back_button4->getContentSize().height+back_button4->getContentSize().height));
	this->addChild(num5,3);

CCLabelTTF* num6=CCLabelTTF::create("6","Arial",35);
			num6->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button6->getContentSize().width-back_button6->getContentSize().width,visibleSize.height/2+origin.y+20+back_button6->getContentSize().height));
			this->addChild(num6,3);
CCLabelTTF* num7=CCLabelTTF::create("7","Arial",35);
	num7->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button7->getContentSize().width,visibleSize.height/2+origin.y+20+back_button7->getContentSize().height));
	this->addChild(num7,3);
CCLabelTTF* num8=CCLabelTTF::create("8","Arial",35);
	num8->setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20+back_button8->getContentSize().height));
	this->addChild(num8,3);
CCLabelTTF* num9=CCLabelTTF::create("9","Arial",35);
	num9->setPosition(ccp(10+origin.x+visibleSize.width/2+back_button9->getContentSize().width,visibleSize.height/2+origin.y+20+back_button9->getContentSize().height));
	this->addChild(num9,3);
CCLabelTTF* num10=CCLabelTTF::create("10","Arial",35);
		num10->setPosition(ccp(10+origin.x+visibleSize.width/2+back_button10->getContentSize().width+back_button10->getContentSize().width,visibleSize.height/2+origin.y+20+back_button10->getContentSize().height));
		this->addChild(num10,3);
CCLabelTTF* num11=CCLabelTTF::create("11","Arial",35);
	num11->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button11->getContentSize().width-back_button11->getContentSize().width,visibleSize.height/2+origin.y+20));
	this->addChild(num11,3);
CCLabelTTF* num12=CCLabelTTF::create("12","Arial",35);
	num12->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button12->getContentSize().width,visibleSize.height/2+origin.y+20));
	this->addChild(num12,3);
CCLabelTTF* num13=CCLabelTTF::create("13","Arial",35);
	num13->setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20));
	this->addChild(num13,3);
CCLabelTTF* num14=CCLabelTTF::create("14","Arial",35);
	num14-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button12->getContentSize().width,visibleSize.height/2+origin.y+20));
	this->addChild(num14,3);
CCLabelTTF* num15=CCLabelTTF::create("15","Arial",35);
	num15->setPosition(ccp(10+origin.x+visibleSize.width/2+back_button12->getContentSize().width+back_button12->getContentSize().width,visibleSize.height/2+origin.y+20));
	this->addChild(num15,3);
CCLabelTTF* num16=CCLabelTTF::create("16","Arial",35);
	num16->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button16->getContentSize().width-back_button1->getContentSize().width,visibleSize.height/2+origin.y+20-back_button16->getContentSize().height));
	this->addChild(num16,3);
CCLabelTTF* num17=CCLabelTTF::create("17","Arial",35);
	num17->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button17->getContentSize().width,visibleSize.height/2+origin.y+20-back_button17->getContentSize().height));
	this->addChild(num17,3);
CCLabelTTF* num18=CCLabelTTF::create("18","Arial",35);
	num18->setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20-back_button18->getContentSize().height));
	this->addChild(num18,3);
CCLabelTTF* num19=CCLabelTTF::create("19","Arial",35);
	num19->setPosition(ccp(10+origin.x+visibleSize.width/2+back_button19->getContentSize().width,visibleSize.height/2+origin.y+20-back_button19->getContentSize().height));
	this->addChild(num19,3);
CCLabelTTF* num20=CCLabelTTF::create("20","Arial",35);
	num20->setPosition(ccp(10+origin.x+visibleSize.width/2+back_button20->getContentSize().width+back_button20->getContentSize().width,visibleSize.height/2+origin.y+20-back_button20->getContentSize().height));
	this->addChild(num20,3);
CCLabelTTF* num21=CCLabelTTF::create("21","Arial",35);
	num21->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button21->getContentSize().width-back_button21->getContentSize().width,visibleSize.height/2+origin.y+20-back_button21->getContentSize().height-back_button21->getContentSize().height));
	this->addChild(num21,3);
	CCLabelTTF* num22=CCLabelTTF::create("22","Arial",35);
		num22->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button1->getContentSize().width,visibleSize.height/2+origin.y+20-back_button2->getContentSize().height-back_button2->getContentSize().height));
		this->addChild(num22,3);
CCLabelTTF* num23=CCLabelTTF::create("23","Arial",35);
	num23->setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20-back_button23->getContentSize().height-back_button23->getContentSize().height));
	this->addChild(num23,3);
CCLabelTTF* num24=CCLabelTTF::create("24","Arial",35);
	num24->setPosition(ccp(10+origin.x+visibleSize.width/2+back_button24->getContentSize().width,visibleSize.height/2+origin.y+20-back_button24->getContentSize().height-back_button24->getContentSize().height));
	this->addChild(num24,3);
CCLabelTTF* num25=CCLabelTTF::create("25","Arial",35);
	num25->setPosition(ccp(10+origin.x+visibleSize.width/2+back_button25->getContentSize().width+back_button25->getContentSize().width,visibleSize.height/2+origin.y+20-back_button25->getContentSize().height-back_button25->getContentSize().height));
	this->addChild(num25,3);

	CCMenu *pMenui=CCMenu::create(back_button,back_button1,back_button2,back_button3,back_button4,back_button5,back_button6,back_button7,back_button8,back_button9,back_button10,back_button11,back_button12,back_button13,back_button14,back_button15,back_button16,back_button17,back_button18,back_button19,back_button20,back_button21,back_button22,back_button23,back_button24,back_button25,NULL);
	pMenui->setPosition(CCPointZero);
	this->addChild(pMenui,2);
	}
}


void HelloWorld::level2pack()
{
	if(unlocking==0)
	{
	if(levelpack2unclock==1)
	{

	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	CCSize windowSize=CCDirector::sharedDirector()->getWinSize();
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	CCMenuItemImage *back_button1=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button1-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button1->getContentSize().width-back_button1->getContentSize().width,visibleSize.height/2+origin.y+20+back_button1->getContentSize().height+back_button1->getContentSize().height+10));
	back_button1->setTag(426);

	CCMenuItemImage *back_button2=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button2-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button2->getContentSize().width,visibleSize.height/2+origin.y+20+back_button2->getContentSize().height+back_button2->getContentSize().height));
	back_button2->setTag(427);

	CCMenuItemImage *back_button3=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button3-> setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20+back_button3->getContentSize().height+back_button3->getContentSize().height));
	back_button3->setTag(428);

	CCMenuItemImage *back_button4=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button4-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button4->getContentSize().width,visibleSize.height/2+origin.y+20+back_button4->getContentSize().height+back_button4->getContentSize().height));
	back_button4->setTag(429);

	CCMenuItemImage *back_button5=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button5-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button4->getContentSize().width+back_button4->getContentSize().width,visibleSize.height/2+origin.y+20+back_button4->getContentSize().height+back_button4->getContentSize().height));
	back_button5->setTag(430);

	CCMenuItemImage *back_button6=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button6-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button6->getContentSize().width-back_button6->getContentSize().width,visibleSize.height/2+origin.y+20+back_button6->getContentSize().height));
	back_button6->setTag(431);

	CCMenuItemImage *back_button7=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button7-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button7->getContentSize().width,visibleSize.height/2+origin.y+20+back_button7->getContentSize().height));
	back_button6->setTag(432);

	CCMenuItemImage *back_button8=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button8-> setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20+back_button8->getContentSize().height));
	back_button8->setTag(433);

	CCMenuItemImage *back_button9=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button9-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button9->getContentSize().width,visibleSize.height/2+origin.y+20+back_button9->getContentSize().height));
	back_button9->setTag(434);

	CCMenuItemImage *back_button10=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button10-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button10->getContentSize().width+back_button10->getContentSize().width,visibleSize.height/2+origin.y+20+back_button10->getContentSize().height));
	back_button10->setTag(435);

	CCMenuItemImage *back_button11=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button11-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button11->getContentSize().width-back_button11->getContentSize().width,visibleSize.height/2+origin.y+20));
	back_button11->setTag(436);

	CCMenuItemImage *back_button12=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button12-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button12->getContentSize().width,visibleSize.height/2+origin.y+20));
	back_button12->setTag(437);

	CCMenuItemImage *back_button13=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button13-> setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20));
	back_button13->setTag(438);

	CCMenuItemImage *back_button14=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button14-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button12->getContentSize().width,visibleSize.height/2+origin.y+20));
	back_button14->setTag(439);

	CCMenuItemImage *back_button15=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button15-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button12->getContentSize().width+back_button12->getContentSize().width,visibleSize.height/2+origin.y+20));
	back_button15->setTag(440);

	CCMenuItemImage *back_button16=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button16-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button16->getContentSize().width-back_button1->getContentSize().width,visibleSize.height/2+origin.y+20-back_button16->getContentSize().height));
	back_button16->setTag(441);

	CCMenuItemImage *back_button17=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button17-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button17->getContentSize().width,visibleSize.height/2+origin.y+20-back_button17->getContentSize().height));
	back_button17->setTag(442);

	CCMenuItemImage *back_button18=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button18-> setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20-back_button18->getContentSize().height));
	back_button18->setTag(443);

	CCMenuItemImage *back_button19=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button19-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button19->getContentSize().width,visibleSize.height/2+origin.y+20-back_button19->getContentSize().height));
	back_button19->setTag(444);

	CCMenuItemImage *back_button20=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button20-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button20->getContentSize().width+back_button20->getContentSize().width,visibleSize.height/2+origin.y+20-back_button20->getContentSize().height));
	back_button20->setTag(445);

	CCMenuItemImage *back_button21=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button21-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button21->getContentSize().width-back_button21->getContentSize().width,visibleSize.height/2+origin.y+20-back_button21->getContentSize().height-back_button21->getContentSize().height));
	back_button21->setTag(446);

	CCMenuItemImage *back_button22=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button22-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button22->getContentSize().width,visibleSize.height/2+origin.y+20-back_button22->getContentSize().height-back_button22->getContentSize().height));
	back_button22->setTag(447);

	CCMenuItemImage *back_button23=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button23-> setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20-back_button23->getContentSize().height-back_button23->getContentSize().height));
	back_button23->setTag(448);

	CCMenuItemImage *back_button24=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button24-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button24->getContentSize().width,visibleSize.height/2+origin.y+20-back_button24->getContentSize().height-back_button24->getContentSize().height));
	back_button24->setTag(449);

	CCMenuItemImage *back_button25=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button25-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button25->getContentSize().width+back_button25->getContentSize().width,visibleSize.height/2+origin.y+20-back_button25->getContentSize().height-back_button25->getContentSize().height));
	back_button25->setTag(450);

	this->removeAllChildren();
	HelloWorld::addbackground();
	CCSprite *imj=CCSprite::create("bg_level_completed@2x.png");
	CCSprite *imj1=CCSprite::create("bg_level@2x.png");


	CCLabelTTF* select_level=CCLabelTTF::create("Select Level","Arial",35);
	select_level->setPosition(ccp(windowSize.width-375,windowSize.height-40));
	this->addChild(select_level,1);

	CCMenuItemImage *back_button=CCMenuItemImage::create("back@2x.png","back@2x.png",this,menu_selector(HelloWorld::mainscene));
	back_button-> setPosition(ccp(40,windowSize.height-55));

	//levels
if(levelicon26 == 1)
	{
		back_button1->setNormalImage(imj);
    }
if(levelicon27 == 1)
	{
		back_button2->setNormalImage(imj);
	}
 if(levelicon28 == 1)
	{
	 back_button3->setNormalImage(imj);
	}
if(levelicon29 == 1)
	{
	back_button4->setNormalImage(imj);
	}

if(levelicon30 == 1)
	{
	back_button5->setNormalImage(imj);
	}

if(levelicon31 == 1)
	{
	back_button6->setNormalImage(imj);
	}

if(levelicon32 == 1)
	{
	back_button7->setNormalImage(imj);
	}

if(levelicon33 == 1)
	{
	back_button8->setNormalImage(imj);
	}

if(levelicon34 == 1)
	{
	back_button9->setNormalImage(imj);
	}

if(levelicon35 == 1)
	{
	back_button10->setNormalImage(imj);
	}
if(levelicon36 == 1)
	{
	back_button11->setNormalImage(imj);
	}
if(levelicon37 == 1)
	{
	back_button12->setNormalImage(imj);
	}
if(levelicon38 == 1)
	{
	back_button13->setNormalImage(imj);
	}
if(levelicon39 == 1)
    {
	back_button14->setNormalImage(imj);
    }
if(levelicon40 == 1)
	{
	back_button15->setNormalImage(imj);
	}
if(levelicon41 == 1)
	{
	back_button16->setNormalImage(imj);
	}

if(levelicon42 == 1)
	{
	back_button17->setNormalImage(imj);
	}

if(levelicon43 == 1)
	{
	back_button18->setNormalImage(imj);
	}

if(levelicon44 == 1)
	{
	back_button19->setNormalImage(imj);
	}
if(levelicon45 == 1)
	{
	back_button20->setNormalImage(imj);
	}
if(levelicon46 == 1)
	{
	back_button21->setNormalImage(imj);
	}
if(levelicon47 == 1)
	{
	back_button22->setNormalImage(imj);
	}

if(levelicon48 == 1)
	{
	back_button23->setNormalImage(imj);
	}

if(levelicon49 == 1)
	{
	back_button24->setNormalImage(imj);
	}

if(levelicon50 == 1)
	{
	back_button25->setNormalImage(imj);
	}

CCLabelTTF* num1=CCLabelTTF::create("1","Arial",35);
	num1->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button1->getContentSize().width-back_button1->getContentSize().width,visibleSize.height/2+origin.y+20+back_button1->getContentSize().height+back_button1->getContentSize().height+10));
	this->addChild(num1,3);
CCLabelTTF* num2=CCLabelTTF::create("2","Arial",35);
	num2->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button2->getContentSize().width,visibleSize.height/2+origin.y+20+back_button2->getContentSize().height+back_button2->getContentSize().height));
	this->addChild(num2,3);
CCLabelTTF* num3=CCLabelTTF::create("3","Arial",35);
	num3->setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20+back_button3->getContentSize().height+back_button3->getContentSize().height));
	this->addChild(num3,3);
CCLabelTTF* num4=CCLabelTTF::create("4","Arial",35);
	num4->setPosition(ccp(10+origin.x+visibleSize.width/2+back_button4->getContentSize().width,visibleSize.height/2+origin.y+20+back_button4->getContentSize().height+back_button4->getContentSize().height));
	this->addChild(num4,3);
CCLabelTTF* num5=CCLabelTTF::create("5","Arial",35);
	num5->setPosition(ccp(10+origin.x+visibleSize.width/2+back_button4->getContentSize().width+back_button4->getContentSize().width,visibleSize.height/2+origin.y+20+back_button4->getContentSize().height+back_button4->getContentSize().height));
	this->addChild(num5,3);

CCLabelTTF* num6=CCLabelTTF::create("6","Arial",35);
			num6->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button6->getContentSize().width-back_button6->getContentSize().width,visibleSize.height/2+origin.y+20+back_button6->getContentSize().height));
			this->addChild(num6,3);
CCLabelTTF* num7=CCLabelTTF::create("7","Arial",35);
	num7->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button7->getContentSize().width,visibleSize.height/2+origin.y+20+back_button7->getContentSize().height));
	this->addChild(num7,3);
CCLabelTTF* num8=CCLabelTTF::create("8","Arial",35);
	num8->setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20+back_button8->getContentSize().height));
	this->addChild(num8,3);
CCLabelTTF* num9=CCLabelTTF::create("9","Arial",35);
	num9->setPosition(ccp(10+origin.x+visibleSize.width/2+back_button9->getContentSize().width,visibleSize.height/2+origin.y+20+back_button9->getContentSize().height));
	this->addChild(num9,3);
CCLabelTTF* num10=CCLabelTTF::create("10","Arial",35);
		num10->setPosition(ccp(10+origin.x+visibleSize.width/2+back_button10->getContentSize().width+back_button10->getContentSize().width,visibleSize.height/2+origin.y+20+back_button10->getContentSize().height));
		this->addChild(num10,3);
CCLabelTTF* num11=CCLabelTTF::create("11","Arial",35);
	num11->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button11->getContentSize().width-back_button11->getContentSize().width,visibleSize.height/2+origin.y+20));
	this->addChild(num11,3);
CCLabelTTF* num12=CCLabelTTF::create("12","Arial",35);
	num12->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button12->getContentSize().width,visibleSize.height/2+origin.y+20));
	this->addChild(num12,3);
CCLabelTTF* num13=CCLabelTTF::create("13","Arial",35);
	num13->setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20));
	this->addChild(num13,3);
CCLabelTTF* num14=CCLabelTTF::create("14","Arial",35);
	num14-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button12->getContentSize().width,visibleSize.height/2+origin.y+20));
	this->addChild(num14,3);
CCLabelTTF* num15=CCLabelTTF::create("15","Arial",35);
	num15->setPosition(ccp(10+origin.x+visibleSize.width/2+back_button12->getContentSize().width+back_button12->getContentSize().width,visibleSize.height/2+origin.y+20));
	this->addChild(num15,3);
CCLabelTTF* num16=CCLabelTTF::create("16","Arial",35);
	num16->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button16->getContentSize().width-back_button1->getContentSize().width,visibleSize.height/2+origin.y+20-back_button16->getContentSize().height));
	this->addChild(num16,3);
CCLabelTTF* num17=CCLabelTTF::create("17","Arial",35);
	num17->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button17->getContentSize().width,visibleSize.height/2+origin.y+20-back_button17->getContentSize().height));
	this->addChild(num17,3);
CCLabelTTF* num18=CCLabelTTF::create("18","Arial",35);
	num18->setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20-back_button18->getContentSize().height));
	this->addChild(num18,3);
CCLabelTTF* num19=CCLabelTTF::create("19","Arial",35);
	num19->setPosition(ccp(10+origin.x+visibleSize.width/2+back_button19->getContentSize().width,visibleSize.height/2+origin.y+20-back_button19->getContentSize().height));
	this->addChild(num19,3);
CCLabelTTF* num20=CCLabelTTF::create("20","Arial",35);
	num20->setPosition(ccp(10+origin.x+visibleSize.width/2+back_button20->getContentSize().width+back_button20->getContentSize().width,visibleSize.height/2+origin.y+20-back_button20->getContentSize().height));
	this->addChild(num20,3);
CCLabelTTF* num21=CCLabelTTF::create("21","Arial",35);
	num21->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button21->getContentSize().width-back_button21->getContentSize().width,visibleSize.height/2+origin.y+20-back_button21->getContentSize().height-back_button21->getContentSize().height));
	this->addChild(num21,3);
	CCLabelTTF* num22=CCLabelTTF::create("22","Arial",35);
			num22->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button1->getContentSize().width,visibleSize.height/2+origin.y+20-back_button2->getContentSize().height-back_button2->getContentSize().height));
			this->addChild(num22,3);
CCLabelTTF* num23=CCLabelTTF::create("23","Arial",35);
	num23->setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20-back_button23->getContentSize().height-back_button23->getContentSize().height));
	this->addChild(num23,3);
CCLabelTTF* num24=CCLabelTTF::create("24","Arial",35);
	num24->setPosition(ccp(10+origin.x+visibleSize.width/2+back_button24->getContentSize().width,visibleSize.height/2+origin.y+20-back_button24->getContentSize().height-back_button24->getContentSize().height));
	this->addChild(num24,3);
CCLabelTTF* num25=CCLabelTTF::create("25","Arial",35);
	num25->setPosition(ccp(10+origin.x+visibleSize.width/2+back_button25->getContentSize().width+back_button25->getContentSize().width,visibleSize.height/2+origin.y+20-back_button25->getContentSize().height-back_button25->getContentSize().height));
	this->addChild(num25,3);

	CCMenu *pMenui=CCMenu::create(back_button,back_button1,back_button2,back_button3,back_button4,back_button5,back_button6,back_button7,back_button8,back_button9,back_button10,back_button11,back_button12,back_button13,back_button14,back_button15,back_button16,back_button17,back_button18,back_button19,back_button20,back_button21,back_button22,back_button23,back_button24,back_button25,NULL);
	pMenui->setPosition(CCPointZero);
	this->addChild(pMenui,2);
	}
	}
}


void HelloWorld::level3pack()
{
	if(unlocking==0)
	{
	if(levelpack3unclock==1)
	{
				CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
			    CCSize windowSize=CCDirector::sharedDirector()->getWinSize();
			    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	CCMenuItemImage *back_button1=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button1-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button1->getContentSize().width-back_button1->getContentSize().width,visibleSize.height/2+origin.y+20+back_button1->getContentSize().height+back_button1->getContentSize().height+10));
	back_button1->setTag(451);

	CCMenuItemImage *back_button2=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button2-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button2->getContentSize().width,visibleSize.height/2+origin.y+20+back_button2->getContentSize().height+back_button2->getContentSize().height));
	back_button2->setTag(452);

	CCMenuItemImage *back_button3=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button3-> setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20+back_button3->getContentSize().height+back_button3->getContentSize().height));
	back_button3->setTag(453);

	CCMenuItemImage *back_button4=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button4-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button4->getContentSize().width,visibleSize.height/2+origin.y+20+back_button4->getContentSize().height+back_button4->getContentSize().height));
	back_button4->setTag(454);

	CCMenuItemImage *back_button5=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button5-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button4->getContentSize().width+back_button4->getContentSize().width,visibleSize.height/2+origin.y+20+back_button4->getContentSize().height+back_button4->getContentSize().height));
	back_button5->setTag(455);

	CCMenuItemImage *back_button6=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button6-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button6->getContentSize().width-back_button6->getContentSize().width,visibleSize.height/2+origin.y+20+back_button6->getContentSize().height));
	back_button6->setTag(456);

	CCMenuItemImage *back_button7=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button7-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button7->getContentSize().width,visibleSize.height/2+origin.y+20+back_button7->getContentSize().height));
	back_button6->setTag(457);

	CCMenuItemImage *back_button8=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button8-> setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20+back_button8->getContentSize().height));
	back_button8->setTag(458);

	CCMenuItemImage *back_button9=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button9-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button9->getContentSize().width,visibleSize.height/2+origin.y+20+back_button9->getContentSize().height));
	back_button9->setTag(459);

	CCMenuItemImage *back_button10=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button10-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button10->getContentSize().width+back_button10->getContentSize().width,visibleSize.height/2+origin.y+20+back_button10->getContentSize().height));
	back_button10->setTag(460);

	CCMenuItemImage *back_button11=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button11-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button11->getContentSize().width-back_button11->getContentSize().width,visibleSize.height/2+origin.y+20));
	back_button11->setTag(461);

	CCMenuItemImage *back_button12=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button12-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button12->getContentSize().width,visibleSize.height/2+origin.y+20));
	back_button12->setTag(462);

	CCMenuItemImage *back_button13=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button13-> setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20));
	back_button13->setTag(463);

	CCMenuItemImage *back_button14=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button14-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button12->getContentSize().width,visibleSize.height/2+origin.y+20));
	back_button14->setTag(464);

	CCMenuItemImage *back_button15=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button15-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button12->getContentSize().width+back_button12->getContentSize().width,visibleSize.height/2+origin.y+20));
	back_button15->setTag(465);

	CCMenuItemImage *back_button16=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button16-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button16->getContentSize().width-back_button1->getContentSize().width,visibleSize.height/2+origin.y+20-back_button16->getContentSize().height));
	back_button16->setTag(466);

	CCMenuItemImage *back_button17=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button17-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button17->getContentSize().width,visibleSize.height/2+origin.y+20-back_button17->getContentSize().height));
	back_button17->setTag(467);

	CCMenuItemImage *back_button18=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button18-> setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20-back_button18->getContentSize().height));
	back_button18->setTag(468);

	CCMenuItemImage *back_button19=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button19-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button19->getContentSize().width,visibleSize.height/2+origin.y+20-back_button19->getContentSize().height));
	back_button19->setTag(469);

	CCMenuItemImage *back_button20=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button20-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button20->getContentSize().width+back_button20->getContentSize().width,visibleSize.height/2+origin.y+20-back_button20->getContentSize().height));
	back_button20->setTag(470);

	CCMenuItemImage *back_button21=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button21-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button21->getContentSize().width-back_button21->getContentSize().width,visibleSize.height/2+origin.y+20-back_button21->getContentSize().height-back_button21->getContentSize().height));
	back_button21->setTag(471);

	CCMenuItemImage *back_button22=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button22-> setPosition(ccp(10+origin.x+visibleSize.width/2-back_button22->getContentSize().width,visibleSize.height/2+origin.y+20-back_button22->getContentSize().height-back_button22->getContentSize().height));
	back_button22->setTag(472);

	CCMenuItemImage *back_button23=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button23-> setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20-back_button23->getContentSize().height-back_button23->getContentSize().height));
	back_button23->setTag(473);

	CCMenuItemImage *back_button24=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button24-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button24->getContentSize().width,visibleSize.height/2+origin.y+20-back_button24->getContentSize().height-back_button24->getContentSize().height));
	back_button24->setTag(474);

	CCMenuItemImage *back_button25=CCMenuItemImage::create("bg_level@2x.png","bg_level@2x.png",this,menu_selector(HelloWorld::deff));
	back_button25-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button25->getContentSize().width+back_button25->getContentSize().width,visibleSize.height/2+origin.y+20-back_button25->getContentSize().height-back_button25->getContentSize().height));
	back_button25->setTag(475);

	this->removeAllChildren();
	HelloWorld::addbackground();
	CCSprite *imj=CCSprite::create("bg_level_completed@2x.png");
	CCSprite *imj1=CCSprite::create("bg_level@2x.png");


	CCLabelTTF* select_level=CCLabelTTF::create("Select Level","Arial",35);
	    select_level->setPosition(ccp(windowSize.width-375,windowSize.height-40));
	    this->addChild(select_level,1);

	CCMenuItemImage *back_button=CCMenuItemImage::create("back@2x.png","back@2x.png",this,menu_selector(HelloWorld::mainscene));
	back_button-> setPosition(ccp(40,windowSize.height-55));

	//levels
if(levelicon51 == 1)
	{
		back_button1->setNormalImage(imj);
    }
if(levelicon52 == 1)
	{
		back_button2->setNormalImage(imj);
	}
 if(levelicon53 == 1)
	{
	 back_button3->setNormalImage(imj);
	}
if(levelicon54 == 1)
	{
	back_button4->setNormalImage(imj);
	}

if(levelicon55 == 1)
	{
	back_button5->setNormalImage(imj);
	}

if(levelicon56 == 1)
	{
	back_button6->setNormalImage(imj);
	}

if(levelicon57 == 1)
	{
	back_button7->setNormalImage(imj);
	}

if(levelicon58 == 1)
	{
	back_button8->setNormalImage(imj);
	}

if(levelicon59 == 1)
	{
	back_button9->setNormalImage(imj);
	}

if(levelicon60 == 1)
	{
	back_button10->setNormalImage(imj);
	}
if(levelicon61 == 1)
	{
	back_button11->setNormalImage(imj);
	}
if(levelicon62 == 1)
	{
	back_button12->setNormalImage(imj);
	}
if(levelicon63 == 1)
	{
	back_button13->setNormalImage(imj);
	}
if(levelicon64 == 1)
    {
	back_button14->setNormalImage(imj);
    }
if(levelicon65 == 1)
	{
	back_button15->setNormalImage(imj);
	}
if(levelicon66 == 1)
	{
	back_button16->setNormalImage(imj);
	}

if(levelicon67 == 1)
	{
	back_button17->setNormalImage(imj);
	}

if(levelicon68 == 1)
	{
	back_button18->setNormalImage(imj);
	}

if(levelicon69 == 1)
	{
	back_button19->setNormalImage(imj);
	}
if(levelicon70 == 1)
	{
	back_button20->setNormalImage(imj);
	}
if(levelicon71 == 1)
	{
	back_button21->setNormalImage(imj);
	}
if(levelicon72 == 1)
	{
	back_button22->setNormalImage(imj);
	}

if(levelicon73 == 1)
	{
	back_button23->setNormalImage(imj);
	}

if(levelicon74 == 1)
	{
	back_button24->setNormalImage(imj);
	}

if(levelicon75 == 1)
	{
	back_button25->setNormalImage(imj);
	}

CCLabelTTF* num1=CCLabelTTF::create("1","Arial",35);
	num1->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button1->getContentSize().width-back_button1->getContentSize().width,visibleSize.height/2+origin.y+20+back_button1->getContentSize().height+back_button1->getContentSize().height+10));
	this->addChild(num1,3);
CCLabelTTF* num2=CCLabelTTF::create("2","Arial",35);
	num2->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button2->getContentSize().width,visibleSize.height/2+origin.y+20+back_button2->getContentSize().height+back_button2->getContentSize().height));
	this->addChild(num2,3);
CCLabelTTF* num3=CCLabelTTF::create("3","Arial",35);
	num3->setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20+back_button3->getContentSize().height+back_button3->getContentSize().height));
	this->addChild(num3,3);
CCLabelTTF* num4=CCLabelTTF::create("4","Arial",35);
	num4->setPosition(ccp(10+origin.x+visibleSize.width/2+back_button4->getContentSize().width,visibleSize.height/2+origin.y+20+back_button4->getContentSize().height+back_button4->getContentSize().height));
	this->addChild(num4,3);
CCLabelTTF* num5=CCLabelTTF::create("5","Arial",35);
	num5->setPosition(ccp(10+origin.x+visibleSize.width/2+back_button4->getContentSize().width+back_button4->getContentSize().width,visibleSize.height/2+origin.y+20+back_button4->getContentSize().height+back_button4->getContentSize().height));
	this->addChild(num5,3);

CCLabelTTF* num6=CCLabelTTF::create("6","Arial",35);
			num6->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button6->getContentSize().width-back_button6->getContentSize().width,visibleSize.height/2+origin.y+20+back_button6->getContentSize().height));
			this->addChild(num6,3);
CCLabelTTF* num7=CCLabelTTF::create("7","Arial",35);
	num7->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button7->getContentSize().width,visibleSize.height/2+origin.y+20+back_button7->getContentSize().height));
	this->addChild(num7,3);
CCLabelTTF* num8=CCLabelTTF::create("8","Arial",35);
	num8->setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20+back_button8->getContentSize().height));
	this->addChild(num8,3);
CCLabelTTF* num9=CCLabelTTF::create("9","Arial",35);
	num9->setPosition(ccp(10+origin.x+visibleSize.width/2+back_button9->getContentSize().width,visibleSize.height/2+origin.y+20+back_button9->getContentSize().height));
	this->addChild(num9,3);
CCLabelTTF* num10=CCLabelTTF::create("10","Arial",35);
		num10->setPosition(ccp(10+origin.x+visibleSize.width/2+back_button10->getContentSize().width+back_button10->getContentSize().width,visibleSize.height/2+origin.y+20+back_button10->getContentSize().height));
		this->addChild(num10,3);
CCLabelTTF* num11=CCLabelTTF::create("11","Arial",35);
	num11->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button11->getContentSize().width-back_button11->getContentSize().width,visibleSize.height/2+origin.y+20));
	this->addChild(num11,3);
CCLabelTTF* num12=CCLabelTTF::create("12","Arial",35);
	num12->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button12->getContentSize().width,visibleSize.height/2+origin.y+20));
	this->addChild(num12,3);
CCLabelTTF* num13=CCLabelTTF::create("13","Arial",35);
	num13->setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20));
	this->addChild(num13,3);
CCLabelTTF* num14=CCLabelTTF::create("14","Arial",35);
	num14-> setPosition(ccp(10+origin.x+visibleSize.width/2+back_button12->getContentSize().width,visibleSize.height/2+origin.y+20));
	this->addChild(num14,3);
CCLabelTTF* num15=CCLabelTTF::create("15","Arial",35);
	num15->setPosition(ccp(10+origin.x+visibleSize.width/2+back_button12->getContentSize().width+back_button12->getContentSize().width,visibleSize.height/2+origin.y+20));
	this->addChild(num15,3);
CCLabelTTF* num16=CCLabelTTF::create("16","Arial",35);
	num16->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button16->getContentSize().width-back_button1->getContentSize().width,visibleSize.height/2+origin.y+20-back_button16->getContentSize().height));
	this->addChild(num16,3);
CCLabelTTF* num17=CCLabelTTF::create("17","Arial",35);
	num17->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button17->getContentSize().width,visibleSize.height/2+origin.y+20-back_button17->getContentSize().height));
	this->addChild(num17,3);
CCLabelTTF* num18=CCLabelTTF::create("18","Arial",35);
	num18->setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20-back_button18->getContentSize().height));
	this->addChild(num18,3);
CCLabelTTF* num19=CCLabelTTF::create("19","Arial",35);
	num19->setPosition(ccp(10+origin.x+visibleSize.width/2+back_button19->getContentSize().width,visibleSize.height/2+origin.y+20-back_button19->getContentSize().height));
	this->addChild(num19,3);
CCLabelTTF* num20=CCLabelTTF::create("20","Arial",35);
	num20->setPosition(ccp(10+origin.x+visibleSize.width/2+back_button20->getContentSize().width+back_button20->getContentSize().width,visibleSize.height/2+origin.y+20-back_button20->getContentSize().height));
	this->addChild(num20,3);
CCLabelTTF* num21=CCLabelTTF::create("21","Arial",35);
	num21->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button21->getContentSize().width-back_button21->getContentSize().width,visibleSize.height/2+origin.y+20-back_button21->getContentSize().height-back_button21->getContentSize().height));
	this->addChild(num21,3);
	CCLabelTTF* num22=CCLabelTTF::create("22","Arial",35);
			num22->setPosition(ccp(10+origin.x+visibleSize.width/2-back_button1->getContentSize().width,visibleSize.height/2+origin.y+20-back_button2->getContentSize().height-back_button2->getContentSize().height));
			this->addChild(num22,3);
CCLabelTTF* num23=CCLabelTTF::create("23","Arial",35);
	num23->setPosition(ccp(10+origin.x+visibleSize.width/2,visibleSize.height/2+origin.y+20-back_button23->getContentSize().height-back_button23->getContentSize().height));
	this->addChild(num23,3);
CCLabelTTF* num24=CCLabelTTF::create("24","Arial",35);
	num24->setPosition(ccp(10+origin.x+visibleSize.width/2+back_button24->getContentSize().width,visibleSize.height/2+origin.y+20-back_button24->getContentSize().height-back_button24->getContentSize().height));
	this->addChild(num24,3);
CCLabelTTF* num25=CCLabelTTF::create("25","Arial",35);
	num25->setPosition(ccp(10+origin.x+visibleSize.width/2+back_button25->getContentSize().width+back_button25->getContentSize().width,visibleSize.height/2+origin.y+20-back_button25->getContentSize().height-back_button25->getContentSize().height));
	this->addChild(num25,3);

	CCMenu *pMenui=CCMenu::create(back_button,back_button1,back_button2,back_button3,back_button4,back_button5,back_button6,back_button7,back_button8,back_button9,back_button10,back_button11,back_button12,back_button13,back_button14,back_button15,back_button16,back_button17,back_button18,back_button19,back_button20,back_button21,back_button22,back_button23,back_button24,back_button25,NULL);
	pMenui->setPosition(CCPointZero);
	this->addChild(pMenui,2);
	}
	}
}

void HelloWorld::helper()
{
if(unlocking==0)
{
	unlocking=1;
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();


	    CCSprite* pSprite = CCSprite::create("bg_tips@2x.png");
	    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	    this->addChild(pSprite, 800);
	    pSprite->setTag(102);

	    CCLabelTTF* helpers=CCLabelTTF::create("Helpers","Arial",60);
	    helpers->setPosition(ccp(385,960));
	    helpers->setColor(ccc3(72,61,135));
	    this->addChild(helpers,800);
	    helpers->setTag(102);
	    CCMenuItemImage* pSpritereveal = CCMenuItemImage::create("btn_buy_coins@2x.png","btn_buy_coins@2x.png",this,menu_selector(HelloWorld::revealletter));
	    pSpritereveal->setPosition(ccp(385,830));
	    //this->addChild(pSpritereveal,800);
	   // pSpritereveal->setTag(102);
	    CCLabelTTF* reveal=CCLabelTTF::create("Reveal letter       100","Arial",35);
	    reveal->setPosition(ccp(pSpritereveal->getPosition().x-50,pSpritereveal->getPosition().y));
	    this->addChild(reveal,801);

	    reveal->setTag(102);
	//    CCLabelTTF* display_reveal=CCLabelTTF::create("10","Arial",10);
	//    display_reveal->setPosition(ccp(218,202));
	//    this->addChild(display_reveal);

	    CCMenuItemImage* pSpriteremove = CCMenuItemImage::create("btn_buy_coins@2x.png","btn_buy_coins@2x.png",this,menu_selector(HelloWorld::removeletter));
	    pSpriteremove->setPosition(ccp(pSpritereveal->getPosition().x,pSpritereveal->getPosition().y-150));
	   // this->addChild(pSpriteremove,800);
	   // pSpriteremove->setTag(102);
	    CCLabelTTF* removal=CCLabelTTF::create("Remove letters   200","Arial",35);
	    removal->setPosition(ccp(pSpriteremove->getPosition().x-50,pSpriteremove->getPosition().y));
	    this->addChild(removal,801);
	    removal->setTag(102);

	//    CCLabelTTF* display_remove=CCLabelTTF::create("20","Arial",10);
	//    display_remove->setPosition(ccp(218,202));
	//    this->addChild(display_remove);btn_buy@2x.png


	    CCMenuItemImage *pSprite3 = CCMenuItemImage::create("btn_buy@2x.png","btn_buy@2x.png",this,menu_selector(HelloWorld::buycoins));
	     pSprite3->setPosition(ccp(pSpriteremove->getPosition().x,pSpriteremove->getPosition().y-150));
	     this->addChild(pSprite3,800);
	     pSprite3->setTag(102);
	     CCLabelTTF* buycoins=CCLabelTTF::create("Buy Coins","Arial",35);
	     buycoins->setPosition(ccp(pSprite3->getPosition().x-10,pSprite3->getPosition().y));
	     this->addChild(buycoins,801);
	     buycoins->setTag(102);
	     CCMenuItemImage *pSpriteclose = CCMenuItemImage::create("btn_close@2x.png","btn_close@2x.png",this,menu_selector(HelloWorld::close2));
	     pSpriteclose->setPosition(ccp(pSprite3->getPosition().x,pSprite3->getPosition().y-150));
	    // this->addChild(pSpriteclose,800);

	     CCLabelTTF* close=CCLabelTTF::create("Close","Arial",35);
	     close->setPosition(ccp(pSpriteclose->getPosition().x-5,pSpriteclose->getPosition().y));
	     this->addChild(close,801);
	     close->setTag(102);
	     CCMenu* pMenu1 = CCMenu::create(pSpriteclose,pSpritereveal,pSpriteremove,pSprite3, NULL);
	    	     	      	       pMenu1->setPosition(CCPointZero);
	    	     	      	       this->addChild(pMenu1, 800);
	    	     	      	       pMenu1->setTag(102);
}
}
void HelloWorld::removeletter()
{
	if(coinscnt>=200)
	{
		unlocking=0;
	int len=query[index1].other.length();
	char oth[len];
	std::strcpy(oth,query[index1].other.c_str());
	//int j=-1;
//	while(j<7)
//	{
//		j++;


		for(int i=1,j=0;i<=12;i++)
		{
			if(this->getChildByTag(5000+i)&&this->getChildByTag(i))
			{
			CCLabelTTF *spr=dynamic_cast<CCLabelTTF *>(this->getChildByTag(5000+i));
					CCMenuItemImage *spr1=dynamic_cast<CCMenuItemImage *>(this->getChildByTag(i));
							const char*k=spr->getString();
							strlwr((char *)k);
							char c=k[0];
							if(oth[j]==c)
							{
								j++;
								if(spr1->getPosition().y==432)
								{
									int pok=(int)spr1->getPosition().x;
									switch(query[index1].ans.length())
									{

									case 5:   switch(pok)
											{
												case 209: if(one==1)
															{one=0;}
												    		break;
												case 293: if(two==1){two=0;}
															break;
												case 384: if(three==1){three=0;}
														    break;
												case 475: if(four==1){four=0;}
															break;
												case 559: if(five==1){five=0;}
												            break;
											}
											break;
								case 6:switch(pok)
								{
									case 170: if(one==1)
												{one=0;}
									    		break;
									case 254: if(two==1){two=0;}
												break;
									case 338: if(three==1){three=0;}
											    break;
									case 430: if(four==1){four=0;}
												break;
									case 514: if(five==1){five=0;}
									            break;
									case 598:if(six==1){six=0;}
									            break;
								}
								break;
								case 7:switch(pok)
								{
									case 125: if(one==1)
												{one=0;}
									    		break;
									case 209: if(two==1){two=0;}
												break;
									case 293: if(three==1){three=0;}
											    break;
									case 384: if(four==1){four=0;}
												break;
									case 475: if(five==1){five=0;}
									            break;
									case 559:if(six==1){six=0;}
												break;
									case 643:if(seven==1){seven=0;}
												break;
								}
								break;
								case 3:   switch(pok)
											{

												case 293: if(one==1){one=0;}
															break;
												case 384: if(two==1){two=0;}
															break;
												case 475: if(three==1){three=0;}
															break;

											}
											break;
								case 4:switch(pok)
																{

																	case 254: if(one==1){one=0;}
																				break;
																	case 338: if(two==1){two=0;}
																			    break;
																	case 430: if(three==1){three=0;}
																				break;
																	case 514: if(four==1){four=0;}
																	            break;

																}
																break;
								case 8:switch(pok)
																{
																	case 86: if(one==1)
																				{one=0;}
																	    		break;
																	case 170: if(two==1){two=0;}
																				break;
																	case 254: if(three==1){three=0;}
																			    break;
																	case 338: if(four==1){four=0;}
																				break;
																	case 430: if(five==1){five=0;}
																	            break;
																	case 514:if(six==1){six=0;}
																	            break;
																	case 598:if(seven==1){seven=0;}
																				break;
																	case 672:if(eight==1){eight=0;}
																				break;
																}
																break;


									}
								}
								spr->setVisible(false);
								this->removeChildByTag(5000+i);
								spr1->setVisible(false);
								i=0;

							}

			}

		}





	HelloWorld::close2();
	coinscnt=coinscnt-200;
	char cn[500];
		      	 	      	     sprintf(cn,"%d",coinscnt);
		      	 	      	     labelcoincnt->setString(cn);
	}

}

void HelloWorld::revealletter()
{

	if(coinscnt>=100)
	{
		unlocking=0;
	fprintf(stderr,"hai1");
	int lite=0;
	int len=query[index1].ans.length();
	char an[len];
	int l=len;
	std::strcpy(an,query[index1].ans.c_str());

	fprintf(stderr,"hai2");
	switch(len)
	{

	case 5:
		{fprintf(stderr,"hai3");
	int rand1=rand()%len;

		float xpoints[5]={209,293,384,475,559};
		if(rand1==0&&one==1)
		{
			HelloWorld::revealletter();
		}
		else if(rand1==1&&two==1)
		{
			HelloWorld::revealletter();

		}
		else if(rand1==2&&three==1)
		{
			HelloWorld::revealletter();
		}
		else if(rand1==3&&four==1)
		{
			HelloWorld::revealletter();
		}
		else if(rand1==4&& five==1)
		{
			HelloWorld::revealletter();
		}
		else
		{
	for(std::vector<int>::size_type it=0;it!=arr.size();++it)
	{
		int k=arr[it];
		if(rand1!=k)
		{
			lite=0;
		}
		else
		{
			lite=1;
		}
	}

	fprintf(stderr,"hai4");
	if(lite==0)
	{
	arr.push_back(rand1);
	fprintf(stderr,"hai5");
	for(int i=1;i<=12;i++)
		{
			CCLabelTTF *let=dynamic_cast<CCLabelTTF *>(this->getChildByTag(5000+i));
			CCMenuItemImage *let1=dynamic_cast<CCMenuItemImage *>(this->getChildByTag(i));
			const char*k=let->getString();
			fprintf(stderr,"\nhai6");
			strlwr((char *)k);
			char c=k[0];
			if(an[rand1]==c)
			{
				fprintf(stderr,"hai7");
				CCSprite *name=CCSprite::create("btn_letter@2x.png");
				name->setPosition(this->getChildByTag(i)->getPosition());
				this->removeChildByTag(i,true);
				let1->setVisible(false);
				this->addChild(name,5);
				fprintf(stderr,"hai8");
				if(rand1==0&&one==0)
								{
									one=1;
									xcount[0]=0;
								}
								if(rand1==1&&two==0)
								{
									two=1;
									xcount[1]=0;
								}
								if(rand1==2&&three==0)
								{
									three=1;
									xcount[2]=0;
								}
								if(rand1==3&&four==0)
												{
													four=1;
													xcount[3]=0;
												}

								if(rand1==4&&five==0)
												{
													five=1;
													reveallast=1;
													xcount[4]=0;
												}
								if(name->getPositionY()==432&&name->getPositionX()==209)
																{

																		one=0;
																}
								if(name->getPositionY()==432&&name->getPositionX()==293)
																								{

																										two=0;
																								}
								if(name->getPositionY()==432&&name->getPositionX()==384)
																								{

																										three=0;
																								}
								if(name->getPositionY()==432&&name->getPositionX()==475)
																								{

																										four=0;
																								}
								if(name->getPositionY()==432&&name->getPositionX()==559)
																								{

																										five=0;
																								}

				name->runAction(CCMoveTo::create(0.2,ccp(xpoints[rand1],432)));
				let->runAction(CCMoveTo::create(0.2,ccp(xpoints[rand1],432)));
				fprintf(stderr,"hai9");
				HelloWorld::close2();

				if(one==1&&two==1&&three==1&&four==1&&five==1)
				{
					lastval=4;
					HelloWorld::tick();
				}


				break;
			}
		}

	}
	else
	{
		HelloWorld::revealletter();
	}
		}}
	break;



	case 3:
		{fprintf(stderr,"hai three");
	int rand1=rand()%len;

		float xpoints[3]={293,384,475};
		if(rand1==0&&one==1)
		{
			HelloWorld::revealletter();
		}
		else if(rand1==1&&two==1)
		{
			HelloWorld::revealletter();

		}
		else if(rand1==2&&three==1)
		{
			HelloWorld::revealletter();
		}
				else
		{
	for(std::vector<int>::size_type it=0;it!=arr.size();++it)
	{
		int k=arr[it];
		if(rand1!=k)
		{
			lite=0;
		}
		else
		{
			lite=1;
		}
	}

	fprintf(stderr,"hai4");
	if(lite==0)
	{
	arr.push_back(rand1);
	fprintf(stderr,"hai5");
	for(int i=1;i<=12;i++)
		{
			CCLabelTTF *let=dynamic_cast<CCLabelTTF *>(this->getChildByTag(5000+i));
			CCMenuItemImage *let1=dynamic_cast<CCMenuItemImage *>(this->getChildByTag(i));
			const char*k=let->getString();
			fprintf(stderr,"\nhai6");
			strlwr((char *)k);
			char c=k[0];
			if(an[rand1]==c)
			{
				fprintf(stderr,"hai7");
				CCSprite *name=CCSprite::create("btn_letter@2x.png");
				name->setPosition(this->getChildByTag(i)->getPosition());
				this->removeChildByTag(i,true);
				let1->setVisible(false);
				this->addChild(name,5);
				fprintf(stderr,"hai8");
				if(rand1==0&&one==0)
								{
									one=1;
									xcount[0]=0;
								}
								if(rand1==1&&two==0)
								{
									two=1;
									xcount[1]=0;
								}
								if(rand1==2&&three==0)
								{
									three=1;
									xcount[2]=0;
								}

				name->runAction(CCMoveTo::create(0.2,ccp(xpoints[rand1],432)));
				let->runAction(CCMoveTo::create(0.2,ccp(xpoints[rand1],432)));
				fprintf(stderr,"hai9");
				HelloWorld::close2();

				if(one==1&&two==1&&three==1)
				{
					lastval=2;
					HelloWorld::tick();
				}


				break;
			}
		}

	}
	else
	{
		HelloWorld::revealletter();
	}
		}}
	break;

	case 4:{fprintf(stderr,"hai3");
	int rand1=rand()%len;

		float xpoints[4]={254,338,430,514};
		if(rand1==0&&one==1)
		{
			HelloWorld::revealletter();
		}
		else if(rand1==1&&two==1)
		{
			HelloWorld::revealletter();

		}
		else if(rand1==2&&three==1)
		{
			HelloWorld::revealletter();
		}
		else if(rand1==3&&four==1)
		{
			HelloWorld::revealletter();
		}

		else
		{
	for(std::vector<int>::size_type it=0;it!=arr.size();++it)
	{
		int k=arr[it];
		if(rand1!=k)
		{
			lite=0;
		}
		else
		{
			lite=1;
		}
	}

	fprintf(stderr,"hai4");
	if(lite==0)
	{
	arr.push_back(rand1);
	fprintf(stderr,"hai5");
	for(int i=1;i<=12;i++)
		{
			CCLabelTTF *let=dynamic_cast<CCLabelTTF *>(this->getChildByTag(5000+i));
			CCMenuItemImage *let1=dynamic_cast<CCMenuItemImage *>(this->getChildByTag(i));
			const char*k=let->getString();
			fprintf(stderr,"\nhai6");
			strlwr((char *)k);
			char c=k[0];
			if(an[rand1]==c)
			{
				fprintf(stderr,"hai7");
				CCSprite *name=CCSprite::create("btn_letter@2x.png");
				name->setPosition(this->getChildByTag(i)->getPosition());
				this->removeChildByTag(i,true);
				let1->setVisible(false);
				this->addChild(name,5);
				fprintf(stderr,"hai8");
				if(rand1==0&&one==0)
								{
									one=1;
									xcount[0]=0;
								}
								if(rand1==1&&two==0)
								{
									two=1;
									xcount[1]=0;
								}
								if(rand1==2&&three==0)
								{
									three=1;
									xcount[2]=0;
								}
								if(rand1==3&&four==0)
												{
													four=1;
													xcount[3]=0;
												}

								if(name->getPositionY()==432)
								{
									if(rand1==0)
									{
										one=0;
									}
									if(rand1==1)
																		{
																			two=0;
																		}
									if(rand1==2)
																		{
																			three=0;
																		}
									if(rand1==3)
																		{
																			four=0;
																		}
								}
				name->runAction(CCMoveTo::create(0.2,ccp(xpoints[rand1],432)));
				let->runAction(CCMoveTo::create(0.2,ccp(xpoints[rand1],432)));
				fprintf(stderr,"hai9");
				HelloWorld::close2();

				if(one==1&&two==1&&three==1&&four==1)
				{
					lastval=3;
					HelloWorld::tick();
				}


				break;
			}
		}

	}
	else
	{
		HelloWorld::revealletter();
	}
		}}
	break;


	case 6:{ fprintf(stderr,"hai3");
	int rand1=rand()%len;

		float xpoints[6]={170,254,338,430,514,598};
		if(rand1==0&&one==1)
		{
			HelloWorld::revealletter();
		}
		else if(rand1==1&&two==1)
		{
			HelloWorld::revealletter();

		}
		else if(rand1==2&&three==1)
		{
			HelloWorld::revealletter();
		}
		else if(rand1==3&&four==1)
		{
			HelloWorld::revealletter();
		}
		else if(rand1==4&& five==1)
		{
			HelloWorld::revealletter();
		}
		else if(rand1==5&& six==1)
		{
			HelloWorld::revealletter();
		}
		else
		{
	for(std::vector<int>::size_type it=0;it!=arr.size();++it)
	{
		int k=arr[it];
		if(rand1!=k)
		{
			lite=0;
		}
		else
		{
			lite=1;
		}
	}

	fprintf(stderr,"hai4");
	if(lite==0)
	{
	arr.push_back(rand1);
	fprintf(stderr,"hai5");
	for(int i=1;i<=12;i++)
		{
			CCLabelTTF *let=dynamic_cast<CCLabelTTF *>(this->getChildByTag(5000+i));
			CCMenuItemImage *let1=dynamic_cast<CCMenuItemImage *>(this->getChildByTag(i));
			const char*k=let->getString();
			fprintf(stderr,"\nhai6");
			strlwr((char *)k);
			char c=k[0];
			if(an[rand1]==c)
			{
				fprintf(stderr,"hai7");
				CCSprite *name=CCSprite::create("btn_letter@2x.png");
				name->setPosition(this->getChildByTag(i)->getPosition());
				this->removeChildByTag(i,true);
				let1->setVisible(false);
				this->addChild(name,5);
				fprintf(stderr,"hai8");
				if(rand1==0&&one==0)
								{
									one=1;
									xcount[0]=0;
								}
								if(rand1==1&&two==0)
								{
									two=1;
									xcount[1]=0;
								}
								if(rand1==2&&three==0)
								{
									three=1;
									xcount[2]=0;
								}
								if(rand1==3&&four==0)
												{
													four=1;
													xcount[3]=0;
												}

								if(rand1==4&&five==0)
												{
													five=1;
													xcount[4]=0;
												}
								if(rand1==5&&six==0)
								{
									six=1;
									xcount[5]=0;
								}
				name->runAction(CCMoveTo::create(0.2,ccp(xpoints[rand1],432)));
				let->runAction(CCMoveTo::create(0.2,ccp(xpoints[rand1],432)));
				fprintf(stderr,"hai9");
				HelloWorld::close2();

				if(one==1&&two==1&&three==1&&four==1&&five==1&&six==1)
				{
					lastval=5;
					HelloWorld::tick();
				}


				break;
			}
		}

	}
	else
	{
		HelloWorld::revealletter();
	}
		}}
	break;

	case 7:

		{fprintf(stderr,"hai3");
	int rand1=rand()%len;

		float xpoints[7]={125,209,293,384,475,559,643};
		if(rand1==0&&one==1)
		{
			HelloWorld::revealletter();
		}
		else if(rand1==1&&two==1)
		{
			HelloWorld::revealletter();

		}
		else if(rand1==2&&three==1)
		{
			HelloWorld::revealletter();
		}
		else if(rand1==3&&four==1)
		{
			HelloWorld::revealletter();
		}
		else if(rand1==4&& five==1)
		{
			HelloWorld::revealletter();
		}
		else if(rand1==5&& six==1)
				{
					HelloWorld::revealletter();
				}
		else if(rand1==6&& seven==1)
				{
					HelloWorld::revealletter();
				}
		else
		{
	for(std::vector<int>::size_type it=0;it!=arr.size();++it)
	{
		int k=arr[it];
		if(rand1!=k)
		{
			lite=0;
		}
		else
		{
			lite=1;
		}
	}

	fprintf(stderr,"hai4");
	if(lite==0)
	{
	arr.push_back(rand1);
	fprintf(stderr,"hai5");
	for(int i=1;i<=12;i++)
		{
			CCLabelTTF *let=dynamic_cast<CCLabelTTF *>(this->getChildByTag(5000+i));
			CCMenuItemImage *let1=dynamic_cast<CCMenuItemImage *>(this->getChildByTag(i));
			const char*k=let->getString();
			fprintf(stderr,"\nhai6");
			strlwr((char *)k);
			char c=k[0];
			if(an[rand1]==c)
			{
				fprintf(stderr,"hai7");
				CCSprite *name=CCSprite::create("btn_letter@2x.png");
				name->setPosition(this->getChildByTag(i)->getPosition());
				this->removeChildByTag(i,true);
				let1->setVisible(false);
				this->addChild(name,5);
				fprintf(stderr,"hai8");
				if(rand1==0&&one==0)
								{
									one=1;
									xcount[0]=0;
								}
								if(rand1==1&&two==0)
								{
									two=1;
									xcount[1]=0;
								}
								if(rand1==2&&three==0)
								{
									three=1;
									xcount[2]=0;
								}
								if(rand1==3&&four==0)
												{
													four=1;
													xcount[3]=0;
												}

								if(rand1==4&&five==0)
												{
													five=1;
													xcount[4]=0;
												}
								if(rand1==5&&six==0)
																				{
																					six=1;
																					xcount[5]=0;
																				}
								if(rand1==6&&seven==0)
																				{
																					seven=1;
																					xcount[6]=0;
																				}
				name->runAction(CCMoveTo::create(0.2,ccp(xpoints[rand1],432)));
				let->runAction(CCMoveTo::create(0.2,ccp(xpoints[rand1],432)));
				fprintf(stderr,"hai9");
				HelloWorld::close2();

				if(one==1&&two==1&&three==1&&four==1&&five==1&&six==1&&seven==1)
				{
					lastval=6;
					HelloWorld::tick();
				}


				break;
			}
		}

	}
	else
	{
		HelloWorld::revealletter();
	}
		}
		}
	break;

	case 8:

	{
		fprintf(stderr,"hai3");
	int rand1=rand()%len;

		float xpoints[8]={86,170,254,338,430,514,598,672};
		if(rand1==0&&one==1)
		{
			HelloWorld::revealletter();
		}
		else if(rand1==1&&two==1)
		{
			HelloWorld::revealletter();

		}
		else if(rand1==2&&three==1)
		{
			HelloWorld::revealletter();
		}
		else if(rand1==3&&four==1)
		{
			HelloWorld::revealletter();
		}
		else if(rand1==4&& five==1)
		{
			HelloWorld::revealletter();
		}
		else if(rand1==5&& six==1)
		{
			HelloWorld::revealletter();
		}
		else if(rand1==6&& seven==1)
				{
					HelloWorld::revealletter();
				}
		else if(rand1==7&& eight==1)
				{
					HelloWorld::revealletter();
				}
		else
		{
	for(std::vector<int>::size_type it=0;it!=arr.size();++it)
	{
		int k=arr[it];
		if(rand1!=k)
		{
			lite=0;
		}
		else
		{
			lite=1;
		}
	}

	fprintf(stderr,"hai4");
	if(lite==0)
	{
	arr.push_back(rand1);
	fprintf(stderr,"hai5");
	for(int i=1;i<=12;i++)
		{
			CCLabelTTF *let=dynamic_cast<CCLabelTTF *>(this->getChildByTag(5000+i));
			CCMenuItemImage *let1=dynamic_cast<CCMenuItemImage *>(this->getChildByTag(i));
			const char*k=let->getString();
			fprintf(stderr,"\nhai6");
			strlwr((char *)k);
			char c=k[0];
			if(an[rand1]==c)
			{
				fprintf(stderr,"hai7");
				CCSprite *name=CCSprite::create("btn_letter@2x.png");
				name->setPosition(this->getChildByTag(i)->getPosition());
				this->removeChildByTag(i,true);
				let1->setVisible(false);
				this->addChild(name,5);
				fprintf(stderr,"hai8");
				if(rand1==0&&one==0)
								{
									one=1;
									xcount[0]=0;
								}
								if(rand1==1&&two==0)
								{
									two=1;
									xcount[1]=0;
								}
								if(rand1==2&&three==0)
								{
									three=1;
									xcount[2]=0;
								}
								if(rand1==3&&four==0)
												{
													four=1;
													xcount[3]=0;
												}

								if(rand1==4&&five==0)
												{
													five=1;
													xcount[4]=0;
												}
								if(rand1==5&&six==0)
								{
									six=1;
									xcount[5]=0;
								}
								if(rand1==6&&seven==0)
																{
																	seven=1;
																	xcount[6]=0;
																}
								if(rand1==7&&eight==0)
																{
																	eight=1;
																	xcount[7]=0;
																}
				name->runAction(CCMoveTo::create(0.2,ccp(xpoints[rand1],432)));
				let->runAction(CCMoveTo::create(0.2,ccp(xpoints[rand1],432)));
				fprintf(stderr,"hai9");
				HelloWorld::close2();

				if(one==1&&two==1&&three==1&&four==1&&five==1&&six==1&&seven==1&&eight==1)
				{
					lastval=7;
					HelloWorld::tick();
				}


				break;
			}
		}

	}
	else
	{
		HelloWorld::revealletter();
	}
		}}
	break;



	}
	coinscnt=coinscnt-100;
	char cn[500];
		      	 	      	     sprintf(cn,"%d",coinscnt);
		      	 	      	     labelcoincnt->setString(cn);
	}
}
void HelloWorld::close2()
{
	unlocking=0;
	for(int i=1;i<=9;i++)
		this->removeChildByTag(102,true);
}
void HelloWorld::scalee(CCNode *sender)
{
	if(unlocking==0)
	{

	if(scal==0)
	{
		birdtag=sender->getTag();
		 orginal=sender->getPosition();
		fprintf(stderr,"hackihsdfhs");
		sender->setPosition(ccp(size.width/2,size.height/2+sender->getContentSize().height/2+50));
		sender->runAction(CCSequence::create(CCMoveTo::create(0.06,ccp(size.width/2,size.height/2+sender->getContentSize().height/2+50)),CCScaleBy::create(0.06,2.4),NULL));

		//sender->setContentSize(CCSize(680,590));
		sender->setZOrder(4);
		scal=1;
	}
	else if(scal==1)
	{
		if(sender->getTag()==birdtag)
		{

		fprintf(stderr,"hackihsdfhs");
		//sender->setPosition(ccp(size.width/2,size.height/2+sender->getContentSize().height/2+50));

		sender->runAction(CCSequence::create(CCScaleBy::create(0.06,1/2.4),CCMoveTo::create(0.03,orginal),NULL));

		sender->setZOrder(3);
	scal=0;
		}

	}
	}
}
void HelloWorld::deff(CCNode *sender)
{
	int tg=sender->getTag();
	fprintf(stderr,"deff1");
	switch(tg)
	{
	case 401:
		fprintf(stderr,"deff2");
				index1=0;
				levels=1;
				fprintf(stderr,"deff3");
				levelnos=1;
				one=0;two=0;three=0;four=0;five=0;
				capacityy=query[index1].ans.length();
				x[capacityy]={0.0};
				y[capacityy]={0.0};
				break;
	case 402:
		index1=1;
						levels=2;
						levelnos=2;
						one=0;two=0;three=0;four=0;five=0;
						capacityy=query[index1].ans.length();
						x[capacityy]={0.0};
						y[capacityy]={0.0};
						break;
	case 403:
			index1=2;
							levels=3;
							levelnos=3;
							one=0;two=0;three=0;
							capacityy=query[index1].ans.length();
							x[capacityy]={0.0};
							y[capacityy]={0.0};
							break;
	case 404:
				index1=3;
								levels=4;
								levelnos=4;
								one=0;two=0;three=0;four=0;five=0;six=0;seven=0;
								capacityy=query[index1].ans.length();
								x[capacityy]={0.0};
								y[capacityy]={0.0};
								break;
	case 405:
					index1=4;
									levels=5;
									levelnos=5;
									one=0;two=0;three=0;
									capacityy=query[index1].ans.length();
									x[capacityy]={0.0};
									y[capacityy]={0.0};
									break;
	case 406:
					index1=5;
									levels=6;
									levelnos=6;
									one=0;two=0;three=0;four=0;five=0;six=0;
									capacityy=query[index1].ans.length();
									x[capacityy]={0.0};
									y[capacityy]={0.0};
									break;
	case 407:
					index1=6;
									levels=7;
									levelnos=7;
									one=0;two=0;three=0;four=0;five=0;six=0;seven=0;eight=0;
									capacityy=query[index1].ans.length();
									x[capacityy]={0.0};
									y[capacityy]={0.0};
									break;
	case 408:
					index1=7;
									levels=8;
									levelnos=8;
									one=0;two=0;three=0;four=0;five=0;
									capacityy=query[index1].ans.length();
									x[capacityy]={0.0};
									y[capacityy]={0.0};
									break;
	case 409:
					index1=8;
									levels=9;
									levelnos=9;
									one=0;two=0;three=0;four=0;five=0;six=0;seven=0;
									capacityy=query[index1].ans.length();
									x[capacityy]={0.0};
									y[capacityy]={0.0};
									break;
	case 410:
					index1=9;
									levels=10;
									levelnos=10;
									one=0;two=0;three=0;four=0;five=0;six=0;seven=0;eight=0;
									capacityy=query[index1].ans.length();
									x[capacityy]={0.0};
									y[capacityy]={0.0};
									break;
	case 411:
					index1=10;
									levels=11;
									levelnos=11;
									one=0;two=0;three=0;four=0;five=0;
									capacityy=query[index1].ans.length();
									x[capacityy]={0.0};
									y[capacityy]={0.0};
									break;
	case 412:
					index1=11;
									levels=12;
									levelnos=12;
									one=0;two=0;three=0;four=0;five=0;six=0;
									capacityy=query[index1].ans.length();
									x[capacityy]={0.0};
									y[capacityy]={0.0};
									break;
	case 413:
					index1=12;
									levels=13;
									levelnos=13;
									one=0;two=0;three=0;four=0;
									capacityy=query[index1].ans.length();
									x[capacityy]={0.0};
									y[capacityy]={0.0};
									break;
	case 414:
					index1=13;
									levels=14;
									levelnos=14;
									one=0;two=0;three=0;four=0;five=0;six=0;seven=0;
									capacityy=query[index1].ans.length();
									x[capacityy]={0.0};
									y[capacityy]={0.0};
									break;
	case 415:
					index1=14;
									levels=15;
									levelnos=15;
									one=0;two=0;three=0;four=0;five=0;
									capacityy=query[index1].ans.length();
									x[capacityy]={0.0};
									y[capacityy]={0.0};
									break;
	case 416:
					index1=15;
									levels=16;
									levelnos=16;
									one=0;two=0;three=0;four=0;
									capacityy=query[index1].ans.length();
									x[capacityy]={0.0};
									y[capacityy]={0.0};
									break;
	case 417:
					index1=16;
									levels=17;
									levelnos=17;
									one=0;two=0;three=0;four=0;five=0;six=0;seven=0;
									capacityy=query[index1].ans.length();
									x[capacityy]={0.0};
									y[capacityy]={0.0};
									break;
	case 418:
					index1=17;
									levels=18;
									levelnos=18;
									one=0;two=0;three=0;four=0;
									capacityy=query[index1].ans.length();
									x[capacityy]={0.0};
									y[capacityy]={0.0};
									break;
	case 419:
					index1=18;
									levels=19;
									levelnos=19;
									one=0;two=0;three=0;four=0;five=0;six=0;seven=0;
									capacityy=query[index1].ans.length();
									x[capacityy]={0.0};
									y[capacityy]={0.0};
									break;
	case 420:
					index1=19;
									levels=20;
									levelnos=20;
									one=0;two=0;three=0;four=0;five=0;six=0;seven=0;
									capacityy=query[index1].ans.length();
									x[capacityy]={0.0};
									y[capacityy]={0.0};
									break;
	case 421:
					index1=20;
									levels=21;
									levelnos=21;
									one=0;two=0;three=0;four=0;five=0;six=0;seven=0;eight=0;
									capacityy=query[index1].ans.length();
									x[capacityy]={0.0};
									y[capacityy]={0.0};
									break;
	case 422:
					index1=21;
									levels=22;
									levelnos=22;
									one=0;two=0;three=0;four=0;five=0;six=0;seven=0;
									capacityy=query[index1].ans.length();
									x[capacityy]={0.0};
									y[capacityy]={0.0};
									break;
	case 423:
					index1=22;
									levels=23;
									levelnos=23;
									one=0;two=0;three=0;four=0;
									capacityy=query[index1].ans.length();
									x[capacityy]={0.0};
									y[capacityy]={0.0};
									break;
	case 424:
					index1=23;
									levels=24;
									levelnos=24;
									one=0;two=0;three=0;four=0;five=0;six=0;
									capacityy=query[index1].ans.length();
									x[capacityy]={0.0};
									y[capacityy]={0.0};
									break;
	case 425:
					index1=24;
									levels=25;
									levelnos=25;
									one=0;two=0;three=0;four=0;five=0;six=0;
									capacityy=query[index1].ans.length();
									x[capacityy]={0.0};
									y[capacityy]={0.0};
									break;
	case 426:
					index1=25;
					levels=26;
					levelnos=1;
					one=0;two=0;three=0;four=0;five=0;six=0;seven=0;
					capacityy=query[index1].ans.length();
					x[capacityy]={0.0};
					y[capacityy]={0.0};
					break;
		case 427:
			index1=26;
							levels=27;
							levelnos=2;
							one=0;two=0;three=0;four=0;five=0;six=0;
							capacityy=query[index1].ans.length();
							x[capacityy]={0.0};
							y[capacityy]={0.0};
							break;
		case 428:
				index1=27;
								levels=28;
								levelnos=3;
								one=0;two=0;three=0;four=0;five=0;six=0;
								capacityy=query[index1].ans.length();
								x[capacityy]={0.0};
								y[capacityy]={0.0};
								break;
		case 429:
					index1=28;
									levels=29;
									levelnos=4;
									one=0;two=0;three=0;four=0;five=0;six=0;seven=0;eight=0;
									capacityy=query[index1].ans.length();
									x[capacityy]={0.0};
									y[capacityy]={0.0};
									break;
		case 430:
						index1=29;
										levels=30;
										levelnos=5;
										one=0;two=0;three=0;
										capacityy=query[index1].ans.length();
										x[capacityy]={0.0};
										y[capacityy]={0.0};
										break;
		case 431:
						index1=30;
										levels=31;
										levelnos=6;
										one=0;two=0;three=0;four=0;five=0;six=0;seven=0;
										capacityy=query[index1].ans.length();
										x[capacityy]={0.0};
										y[capacityy]={0.0};
										break;
		case 432:
						index1=31;
										levels=32;
										levelnos=7;
										one=0;two=0;three=0;four=0;five=0;six=0;
										capacityy=query[index1].ans.length();
										x[capacityy]={0.0};
										y[capacityy]={0.0};
										break;
		case 433:
						index1=32;
										levels=33;
										levelnos=8;
										one=0;two=0;three=0;four=0;five=0;
										capacityy=query[index1].ans.length();
										x[capacityy]={0.0};
										y[capacityy]={0.0};
										break;
		case 434:
						index1=33;
										levels=34;
										levelnos=9;
										one=0;two=0;three=0;four=0;
										capacityy=query[index1].ans.length();
										x[capacityy]={0.0};
										y[capacityy]={0.0};
										break;
		case 435:
						index1=34;
										levels=35;
										levelnos=10;
										one=0;two=0;three=0;four=0;
										capacityy=query[index1].ans.length();
										x[capacityy]={0.0};
										y[capacityy]={0.0};
										break;
		case 436:
						index1=35;
										levels=36;
										levelnos=11;
										one=0;two=0;three=0;four=0;five=0;six=0;seven=0;
										capacityy=query[index1].ans.length();
										x[capacityy]={0.0};
										y[capacityy]={0.0};
										break;
		case 437:
						index1=36;
										levels=37;
										levelnos=12;
										one=0;two=0;three=0;four=0;five=0;six=0;seven=0;
										capacityy=query[index1].ans.length();
										x[capacityy]={0.0};
										y[capacityy]={0.0};
										break;
		case 438:
						index1=37;
										levels=38;
										levelnos=13;
										one=0;two=0;three=0;four=0;
										capacityy=query[index1].ans.length();
										x[capacityy]={0.0};
										y[capacityy]={0.0};
										break;
		case 439:
						index1=38;
										levels=39;
										levelnos=14;
										one=0;two=0;three=0;four=0;five=0;six=0;seven=0;
										capacityy=query[index1].ans.length();
										x[capacityy]={0.0};
										y[capacityy]={0.0};
										break;
		case 440:
						index1=39;
										levels=40;
										levelnos=15;
										one=0;two=0;three=0;four=0;five=0;
										capacityy=query[index1].ans.length();
										x[capacityy]={0.0};
										y[capacityy]={0.0};
										break;
		case 441:
						index1=40;
										levels=41;
										levelnos=16;
										one=0;two=0;three=0;four=0;five=0;six=0;seven=0;eight=0;
										capacityy=query[index1].ans.length();
										x[capacityy]={0.0};
										y[capacityy]={0.0};
										break;
		case 442:
						index1=41;
										levels=42;
										levelnos=17;
										one=0;two=0;three=0;
										capacityy=query[index1].ans.length();
										x[capacityy]={0.0};
										y[capacityy]={0.0};
										break;
		case 443:
						index1=42;
										levels=43;
										levelnos=18;
										one=0;two=0;three=0;four=0;five=0;
										capacityy=query[index1].ans.length();
										x[capacityy]={0.0};
										y[capacityy]={0.0};
										break;
		case 444:
						index1=43;
										levels=44;
										levelnos=19;
										one=0;two=0;three=0;four=0;five=0;six=0;seven=0;
										capacityy=query[index1].ans.length();
										x[capacityy]={0.0};
										y[capacityy]={0.0};
										break;
		case 445:
						index1=44;
										levels=45;
										levelnos=20;
										one=0;two=0;three=0;four=0;five=0;six=0;seven=0;eight=0;
										capacityy=query[index1].ans.length();
										x[capacityy]={0.0};
										y[capacityy]={0.0};
										break;
		case 446:
						index1=45;
										levels=46;
										levelnos=21;
										one=0;two=0;three=0;four=0;five=0;six=0;
										capacityy=query[index1].ans.length();
										x[capacityy]={0.0};
										y[capacityy]={0.0};
										break;
		case 447:
						index1=46;
										levels=47;
										levelnos=22;
										one=0;two=0;three=0;four=0;five=0;six=0;
										capacityy=query[index1].ans.length();
										x[capacityy]={0.0};
										y[capacityy]={0.0};
										break;
		case 448:
						index1=47;
										levels=48;
										levelnos=23;
										one=0;two=0;three=0;four=0;
										capacityy=query[index1].ans.length();
										x[capacityy]={0.0};
										y[capacityy]={0.0};
										break;
		case 449:
						index1=48;
										levels=49;
										levelnos=24;
										one=0;two=0;three=0;four=0;five=0;
										capacityy=query[index1].ans.length();
										x[capacityy]={0.0};
										y[capacityy]={0.0};
										break;
		case 450:
						index1=49;
										levels=50;
										levelnos=25;
										one=0;two=0;three=0;four=0;five=0;
										capacityy=query[index1].ans.length();
										x[capacityy]={0.0};
										y[capacityy]={0.0};
										break;
		case 451:
						index1=50;
						levels=51;
						levelnos=1;
						one=0;two=0;three=0;four=0;five=0;
						capacityy=query[index1].ans.length();
						x[capacityy]={0.0};
						y[capacityy]={0.0};
						break;
			case 452:
				index1=51;
								levels=52;
								levelnos=2;
								one=0;two=0;three=0;four=0;five=0;
								capacityy=query[index1].ans.length();
								x[capacityy]={0.0};
								y[capacityy]={0.0};
								break;
			case 453:
					index1=52;
									levels=53;
									levelnos=3;
									one=0;two=0;three=0;four=0;five=0;six=0;
									capacityy=query[index1].ans.length();
									x[capacityy]={0.0};
									y[capacityy]={0.0};
									break;
			case 454:
						index1=53;
										levels=54;
										levelnos=4;
										one=0;two=0;three=0;four=0;
										capacityy=query[index1].ans.length();
										x[capacityy]={0.0};
										y[capacityy]={0.0};
										break;
			case 455:
							index1=54;
											levels=55;
											levelnos=5;
											one=0;two=0;three=0;four=0;five=0;six=0;seven=0;eight=0;
											capacityy=query[index1].ans.length();
											x[capacityy]={0.0};
											y[capacityy]={0.0};
											break;
			case 456:
							index1=55;
											levels=56;
											levelnos=6;
											one=0;two=0;three=0;four=0;
											capacityy=query[index1].ans.length();
											x[capacityy]={0.0};
											y[capacityy]={0.0};
											break;
			case 457:
							index1=56;
											levels=57;
											levelnos=7;
											one=0;two=0;three=0;four=0;five=0;
											capacityy=query[index1].ans.length();
											x[capacityy]={0.0};
											y[capacityy]={0.0};
											break;
			case 458:
							index1=57;
											levels=58;
											levelnos=8;
											one=0;two=0;three=0;four=0;five=0;six=0;seven=0;
											capacityy=query[index1].ans.length();
											x[capacityy]={0.0};
											y[capacityy]={0.0};
											break;
			case 459:
							index1=58;
											levels=59;
											levelnos=9;
											one=0;two=0;three=0;four=0;five=0;
											capacityy=query[index1].ans.length();
											x[capacityy]={0.0};
											y[capacityy]={0.0};
											break;
			case 460:
							index1=59;
											levels=60;
											levelnos=10;
											one=0;two=0;three=0;four=0;five=0;six=0;seven=0;
											capacityy=query[index1].ans.length();
											x[capacityy]={0.0};
											y[capacityy]={0.0};
											break;
			case 461:
							index1=60;
											levels=61;
											levelnos=11;
											one=0;two=0;three=0;four=0;five=0;six=0;seven=0;eight=0;
											capacityy=query[index1].ans.length();
											x[capacityy]={0.0};
											y[capacityy]={0.0};
											break;
			case 462:
							index1=61;
											levels=62;
											levelnos=12;
											one=0;two=0;three=0;four=0;five=0;
											capacityy=query[index1].ans.length();
											x[capacityy]={0.0};
											y[capacityy]={0.0};
											break;
			case 463:
							index1=62;
											levels=63;
											levelnos=13;
											one=0;two=0;three=0;four=0;five=0;
											capacityy=query[index1].ans.length();
											x[capacityy]={0.0};
											y[capacityy]={0.0};
											break;
			case 464:
							index1=63;
											levels=64;
											levelnos=14;
											one=0;two=0;three=0;four=0;five=0;six=0;seven=0;
											capacityy=query[index1].ans.length();
											x[capacityy]={0.0};
											y[capacityy]={0.0};
											break;
			case 465:
							index1=64;
											levels=65;
											levelnos=15;
											one=0;two=0;three=0;four=0;five=0;six=0;seven=0;
											capacityy=query[index1].ans.length();
											x[capacityy]={0.0};
											y[capacityy]={0.0};
											break;
			case 466:
							index1=65;
											levels=66;
											levelnos=16;
											one=0;two=0;three=0;four=0;five=0;six=0;
											capacityy=query[index1].ans.length();
											x[capacityy]={0.0};
											y[capacityy]={0.0};
											break;
			case 467:
							index1=66;
											levels=67;
											levelnos=17;
											one=0;two=0;three=0;four=0;five=0;
											capacityy=query[index1].ans.length();
											x[capacityy]={0.0};
											y[capacityy]={0.0};
											break;
			case 468:
							index1=67;
											levels=68;
											levelnos=18;
											one=0;two=0;three=0;four=0;five=0;six=0;seven=0;
											capacityy=query[index1].ans.length();
											x[capacityy]={0.0};
											y[capacityy]={0.0};
											break;
			case 469:
							index1=68;
											levels=69;
											levelnos=19;
											one=0;two=0;three=0;four=0;five=0;six=0;seven=0;eight=0;
											capacityy=query[index1].ans.length();
											x[capacityy]={0.0};
											y[capacityy]={0.0};
											break;
			case 470:
							index1=69;
											levels=70;
											levelnos=20;
											one=0;two=0;three=0;four=0;five=0;
											capacityy=query[index1].ans.length();
											x[capacityy]={0.0};
											y[capacityy]={0.0};
											break;
			case 471:
							index1=70;
											levels=71;
											levelnos=21;
											one=0;two=0;three=0;four=0;five=0;six=0;seven=0;
											capacityy=query[index1].ans.length();
											x[capacityy]={0.0};
											y[capacityy]={0.0};
											break;
			case 472:
							index1=71;
											levels=72;
											levelnos=22;
											one=0;two=0;three=0;four=0;five=0;six=0;seven=0;eight=0;
											capacityy=query[index1].ans.length();
											x[capacityy]={0.0};
											y[capacityy]={0.0};
											break;
			case 473:
							index1=72;
											levels=73;
											levelnos=23;
											one=0;two=0;three=0;four=0;five=0;six=0;seven=0;eight=0;
											capacityy=query[index1].ans.length();
											x[capacityy]={0.0};
											y[capacityy]={0.0};
											break;
			case 474:
							index1=73;
											levels=74;
											levelnos=24;
											one=0;two=0;three=0;four=0;five=0;six=0;seven=0;
											capacityy=query[index1].ans.length();
											x[capacityy]={0.0};
											y[capacityy]={0.0};
											break;
			case 475:
							index1=74;
											levels=75;
											levelnos=25;
											one=0;two=0;three=0;four=0;five=0;six=0;
											capacityy=query[index1].ans.length();
											x[capacityy]={0.0};
											y[capacityy]={0.0};
											break;
	}
	HelloWorld::level1();
}
void HelloWorld::level1()
{

	this->removeAllChildren();
	arr.empty();
	reveallast=0;
	//this->setTouchEnabled(true);
	HelloWorld::addbackground();
	count=0;

	// x[5]={0;y[5]={0.0};

	CCMenuItemImage *backBtn;
	//////// back button////////////////
	if(levels>0&&levels<26)
	{
	backBtn = CCMenuItemImage::create(
	                                        "back@2x.png",
	                                        "back@2x.png",
	                                        this,
	                                        menu_selector(HelloWorld::level1pack));
	}
	else if(levels>25&&levels<51)
		{
		backBtn = CCMenuItemImage::create(
		                                        "back@2x.png",
		                                        "back@2x.png",
		                                        this,
		                                        menu_selector(HelloWorld::level2pack));
		}
	else if(levels>50&&levels<76)
		{
		backBtn = CCMenuItemImage::create(
		                                        "back@2x.png",
		                                        "back@2x.png",
		                                        this,
		                                        menu_selector(HelloWorld::level3pack));
		}

	backBtn->setPosition(ccp( 70, size.height-70));

///////////// coins .////////////////////


unlocking=0;
	       CCMenuItemImage *coinBtn = CCMenuItemImage::create(
	       	                                        "btn_coins@2x.png",
	       	                                        "btn_coins@2x.png",
	       	                                        this,
	       	                                        menu_selector(HelloWorld::buycoins));

	       coinBtn->setPosition(ccp(size.width-80,size.height-70));

	      	     labelcoincnt=CCLabelTTF::create("0","Arial",35.0f);
	      	     labelcoincnt->setPosition(ccp(coinBtn->getPosition().x-15,coinBtn->getPosition().y));
	      	        this->addChild(labelcoincnt,3);
	      	   char cn[500];
	      	 	      	     sprintf(cn,"%d",coinscnt);
	      	 	      	     labelcoincnt->setString(cn);
	      	 	      	     char labl[10];
	      	 	      	     sprintf(labl,"Level %d",levelnos);
	      	   CCLabelTTF *labelco=CCLabelTTF::create("","ARIAL",35.0f);
	      	 labelco->setPosition(ccp(size.width/2,coinBtn->getPosition().y));
	      	 labelco->setString(labl);
	      	   	      	     this->addChild(labelco,3);

	      	     /////////birds////////////////////////("birdImages/"+query[0].ans+"1.png").c_str()

	      	     CCMenuItemImage *bird1=CCMenuItemImage::create(("birdImages/"+query[index1].ans+"1.png").c_str(),("birdImages/"+query[index1].ans+"1.png").c_str(),this,menu_selector(HelloWorld::scalee));
	      	     bird1->setPosition(ccp(size.width/4,backBtn->getPosition().y-backBtn->getContentSize().height/2-bird1->getContentSize().height/2-50));
	      	     bird1->setTag(814);
	      	    // this->addChild(bird1,3);
	      	   CCMenuItemImage *bird2=CCMenuItemImage::create(("birdImages/"+query[index1].ans+"2.png").c_str(),("birdImages/"+query[index1].ans+"2.png").c_str(),this,menu_selector(HelloWorld::scalee));

	      	   	 bird2->setPosition(ccp((size.width/4)*3,backBtn->getPosition().y-backBtn->getContentSize().height/2-bird1->getContentSize().height/2-50));
	      	   	 //this->addChild(bird2,3);
	      	   	 bird2->setTag(815);
	      	   CCMenuItemImage *bird3=CCMenuItemImage::create(("birdImages/"+query[index1].ans+"3.png").c_str(),("birdImages/"+query[index1].ans+"3.png").c_str(),this,menu_selector(HelloWorld::scalee));

	      	   	 bird3->setPosition(ccp(size.width/4,bird1->getPosition().y-bird1->getContentSize().height/2-bird3->getContentSize().height/2-80));
	      	   	// this->addChild(bird3,3);
	      	   	 bird3->setTag(816);
	      	   CCMenuItemImage *bird4=CCMenuItemImage::create(("birdImages/"+query[index1].ans+"4.png").c_str(),("birdImages/"+query[index1].ans+"4.png").c_str(),this,menu_selector(HelloWorld::scalee));

	      	   	 bird4->setPosition(ccp((size.width/4)*3,bird2->getPosition().y-bird2->getContentSize().height/2-bird4->getContentSize().height/2-80));

	      	   	 //this->addChild(bird4,3);
	      	   	 bird4->setTag(817);
	      	   	 CCMenu *birdsmenu=CCMenu::create(bird1,bird2,bird3,bird4,NULL);
	      	   	 birdsmenu->setPosition(CCPointZero);

	      	   	 this->addChild(birdsmenu,3);

	      	   	 ///////////////////////////Solution Input sprite//////////////////////

	      	   	 solutionback=CCSprite::create("bg_solution@2x.png");
	      	   	 solutionback->setPosition(ccp(size.width/2,bird4->getPosition().y-bird4->getContentSize().height/2-80));
	      	   	 this->addChild(solutionback,3);
	      	   	 //////////////////////////Input boxex////////////////////////////

//	      	   	CCSprite *input=CCSprite::create("btn_input@2x.png");
//
//	      	   		 input->setPosition(ccp(solutionback->getPosition().x,solutionback->getPosition().y));
//	      	   		 this->addChild(input,5);
//	      	   	CCSprite *input1=CCSprite::create("btn_input@2x.png");
//	      	   		 input1->setPosition(ccp(solutionback->getPosition().x-input->getContentSize().width-9,solutionback->getPosition().y));
//	      	   	this->addChild(input1,5);
//	      	  CCSprite *input2=CCSprite::create("btn_input@2x.png");
//	      	  	      	   		 input2->setPosition(ccp(solutionback->getPosition().x-(input->getContentSize().width*2)-9,solutionback->getPosition().y));
//	      	  	      	   	this->addChild(input2,5);
//	      	  	      	CCSprite *input3=CCSprite::create("btn_input@2x.png");
//	      	  	      		      	   		 input3->setPosition(ccp(solutionback->getPosition().x+input->getContentSize().width+9,solutionback->getPosition().y));
//	      	  	      		      	   	this->addChild(input3,5);
//	      	  	      		      CCSprite *input4=CCSprite::create("btn_input@2x.png");
//	      	  	      		      	      	   		 input4->setPosition(ccp(solutionback->getPosition().x+(input->getContentSize().width*2)+9,solutionback->getPosition().y));
//	      	  	      		      	      	   	this->addChild(input4,5);
	      	   	input=CCArray::createWithCapacity(capacityy);
	      	  CCSprite *inputsprite;
	      	  points=CCPointArray::create(capacityy);
	      	  switch(capacityy)
	      	  {


	      	  case 5:   	for(int i=1;i<=5;i++)
	      	   				{
	      		  	  	  	  if(i==3)
	      		  	  	  	  {
	      		  	  	  		  	  inputsprite=CCSprite::create("btn_input@2x.png");

	      		  	  	  		  	  inputsprite->setPosition(ccp(solutionback->getPosition().x,solutionback->getPosition().y));
	      		  	  	  		  	  this->addChild(inputsprite,5);


	      		  	  	  		  	  input->addObject(inputsprite);
	      		  	  	  		  	  points->addControlPoint(ccp(inputsprite->getPosition().x,inputsprite->getPosition().y));
	      		  	  	  	  }
	      		  	  	  	  if(i<3)
	      		  	  	  	  {
	      		  	  	  		  inputsprite=CCSprite::create("btn_input@2x.png");

	      		  	  	  		  inputsprite->setPosition(ccp(solutionback->getPosition().x-(inputsprite->getContentSize().width*i)-7,solutionback->getPosition().y));
	      		  	  	  		  this->addChild(inputsprite,5);

	      		  	  	  		  input->addObject(inputsprite);
	      		  	  	  		  points->addControlPoint(ccp(inputsprite->getPosition().x,inputsprite->getPosition().y));
	      		  	  	  		  inputsprite=CCSprite::create("btn_input@2x.png");

	      		  	  	  		  inputsprite->setPosition(ccp(solutionback->getPosition().x+(inputsprite->getContentSize().width*i)+7,solutionback->getPosition().y));
	      		  	  	  		  this->addChild(inputsprite,5);
	      		  	  	  		  fprintf(stderr,"x:%f,y%f",inputsprite->getPosition().x,inputsprite->getPosition().y);
	      		  	  	  		  points->addControlPoint(ccp(inputsprite->getPosition().x,inputsprite->getPosition().y));
	      		  	  	  		  input->addObject(inputsprite);
	      		  	  	  	  }
	      	   				}
	      	  	  	  	  	 break;
	      	  case 3:	for(int i=1;i<=3;i++)
	      	   			{
	      		  	  	  if(i==2)
	      		  	  	  {
	      		  	  		  	  inputsprite=CCSprite::create("btn_input@2x.png");

	      		  	  		  	  inputsprite->setPosition(ccp(solutionback->getPosition().x,solutionback->getPosition().y));
	      		  	  		  	  this->addChild(inputsprite,5);


	      		  	  		  	  input->addObject(inputsprite);
	      		  	  		  	  points->addControlPoint(ccp(inputsprite->getPosition().x,inputsprite->getPosition().y));
	      		  	  	  }
	      		  	  	  if(i<2)
	      		  	  	  {
	      		  	  		  inputsprite=CCSprite::create("btn_input@2x.png");

	      		  	  		  inputsprite->setPosition(ccp(solutionback->getPosition().x-(inputsprite->getContentSize().width*i)-7,solutionback->getPosition().y));
	      		  	  		  this->addChild(inputsprite,5);

	      		  	  		  input->addObject(inputsprite);
	      		  	  		  points->addControlPoint(ccp(inputsprite->getPosition().x,inputsprite->getPosition().y));
	      		  	  		  inputsprite=CCSprite::create("btn_input@2x.png");

	      		  	  		  inputsprite->setPosition(ccp(solutionback->getPosition().x+(inputsprite->getContentSize().width*i)+7,solutionback->getPosition().y));
	      		  	  		  this->addChild(inputsprite,5);
	      		  	  		  fprintf(stderr,"x:%f,y%f",inputsprite->getPosition().x,inputsprite->getPosition().y);
	      		  	  		  points->addControlPoint(ccp(inputsprite->getPosition().x,inputsprite->getPosition().y));
	      		  	  		  input->addObject(inputsprite);
	      		  	  	  }
	      	   			}
	      	  	  	  break;
	      	  case 7:   	for(int i=1;i<=7;i++)
	      	  	  	  	  	{
	      		  	  	  	  if(i==4)
	      		  	  	  	  {
	      		  	  	  		  inputsprite=CCSprite::create("btn_input@2x.png");

	      		  	  	  		  inputsprite->setPosition(ccp(solutionback->getPosition().x,solutionback->getPosition().y));
	      		  	  	  		  this->addChild(inputsprite,5);
	      		  	  	  		  fprintf(stderr,"x:%f ,y:%f",inputsprite->getPosition().x,inputsprite->getPosition().y);

	      		  	  	  		  input->addObject(inputsprite);
	      		  	  	  		  points->addControlPoint(ccp(inputsprite->getPosition().x,inputsprite->getPosition().y));
	      		  	  	  	  }
	      		  	  	  	  if(i<4)
	      		  	  	  	  {
	      		  	  	  		  inputsprite=CCSprite::create("btn_input@2x.png");

	      		  	  	  		  inputsprite->setPosition(ccp(solutionback->getPosition().x-(inputsprite->getContentSize().width*i)-7,solutionback->getPosition().y));
	      		  	  	  		  this->addChild(inputsprite,5);
	      		  	  	  		  fprintf(stderr,"x:%f ,y:%f",inputsprite->getPosition().x,inputsprite->getPosition().y);

	      		  	  	  		  input->addObject(inputsprite);
	      		  	  	  		  points->addControlPoint(ccp(inputsprite->getPosition().x,inputsprite->getPosition().y));
	      		  	  	  		  inputsprite=CCSprite::create("btn_input@2x.png");

	      		  	  	  		  inputsprite->setPosition(ccp(solutionback->getPosition().x+(inputsprite->getContentSize().width*i)+7,solutionback->getPosition().y));
	      		  	  	  		  this->addChild(inputsprite,5);
	      		  	  	  		  fprintf(stderr,"x:%f,y%f",inputsprite->getPosition().x,inputsprite->getPosition().y);
	      		  	  	  		  points->addControlPoint(ccp(inputsprite->getPosition().x,inputsprite->getPosition().y));
	      		  	  	  		  input->addObject(inputsprite);
	      		  	  	  	  }
	      	  	  	  	  	}
	      	  	  	  	  break;
	      	  case 6:
	      		  	  	  	  	  	  	  	  	  for(int i=1;i<=6;i++)
	      					      		      	   	{
	      					      		      	   	if(i==1)
	      					      		      	   	{
	      					      		      	   	inputsprite=CCSprite::create("btn_input@2x.png");
	      					      		      	   	inputsprite->setPosition(ccp(solutionback->getPosition().x-(inputsprite->getContentSize().width/2*i)-4,solutionback->getPosition().y));
	      					      		      	   	this->addChild(inputsprite,5);
	      					      		      	   	input->addObject(inputsprite);
	      					      		      	   	fprintf(stderr,"\nx: %f and y:%f",inputsprite->getPosition().x,inputsprite->getPosition().y);
	      					      		      	   	inputsprite=CCSprite::create("btn_input@2x.png");
	      					      		      	   	inputsprite->setPosition(ccp(solutionback->getPosition().x+(inputsprite->getContentSize().width/2*i)+4,solutionback->getPosition().y));
	      					      		      	   	this->addChild(inputsprite,5);
	      					      		      	   	input->addObject(inputsprite);
	      					      		      	   	fprintf(stderr,"\nx: %f and y:%f",inputsprite->getPosition().x,inputsprite->getPosition().y);
	      					      		      	   	}
	      					      		      	   	if(i<=3&&i!=1)
	      					      		      	   	{
	      					      		      	    inputsprite=CCSprite::create("btn_input@2x.png");
	      					      		      	   	inputsprite->setPosition(ccp(solutionback->getPosition().x-((inputsprite->getContentSize().width*i)-inputsprite->getContentSize().width/2)-4,solutionback->getPosition().y));
	      					      		      	   	this->addChild(inputsprite,5);
	      					      		      	   	input->addObject(inputsprite);
	      					      		      	   	fprintf(stderr,"\nx: %f and y:%f",inputsprite->getPosition().x,inputsprite->getPosition().y);
	      					      		      	   	inputsprite=CCSprite::create("btn_input@2x.png");
	      					      		      	   	inputsprite->setPosition(ccp(solutionback->getPosition().x+((inputsprite->getContentSize().width*i)-inputsprite->getContentSize().width/2)+4,solutionback->getPosition().y));
	      					      		      	   	this->addChild(inputsprite,5);
	      					      		      	   	input->addObject(inputsprite);
	      					      		      	   	fprintf(stderr,"\nx: %f and y:%f",inputsprite->getPosition().x,inputsprite->getPosition().y);
	      					      		      	   	}
	      					      		      	   	}
	      		  	  	  	  	  	  	  	  	  break;
	      	  case 8:
	      		  for(int i=1;i<=8;i++)
	      			{
	      			if(i==1)
	      			{
	      			inputsprite=CCSprite::create("btn_input@2x.png");
	      			inputsprite->setPosition(ccp(solutionback->getPosition().x-(inputsprite->getContentSize().width/2*i)-4,solutionback->getPosition().y));
	      			this->addChild(inputsprite,5);
	      			input->addObject(inputsprite);
	      			fprintf(stderr,"\nx: %f and y:%f",inputsprite->getPosition().x,inputsprite->getPosition().y);
	      			inputsprite=CCSprite::create("btn_input@2x.png");
	      			inputsprite->setPosition(ccp(solutionback->getPosition().x+(inputsprite->getContentSize().width/2*i)+4,solutionback->getPosition().y));
	      			this->addChild(inputsprite,5);
	      			input->addObject(inputsprite);
	      			fprintf(stderr,"\nx: %f and y:%f",inputsprite->getPosition().x,inputsprite->getPosition().y);
	      			}
	      			if(i<=4&&i!=1)
	      			{
	      			inputsprite=CCSprite::create("btn_input@2x.png");
	      			inputsprite->setPosition(ccp(solutionback->getPosition().x-((inputsprite->getContentSize().width*i)-inputsprite->getContentSize().width/2)-4,solutionback->getPosition().y));
	      			this->addChild(inputsprite,5);
	      			input->addObject(inputsprite);
	      			fprintf(stderr,"\nx: %f and y:%f",inputsprite->getPosition().x,inputsprite->getPosition().y);
	      			inputsprite=CCSprite::create("btn_input@2x.png");
	      			inputsprite->setPosition(ccp(solutionback->getPosition().x+((inputsprite->getContentSize().width*i)-inputsprite->getContentSize().width/2)+4,solutionback->getPosition().y));
	      			this->addChild(inputsprite,5);
	      			input->addObject(inputsprite);
	      			fprintf(stderr,"\nx: %f and y:%f",inputsprite->getPosition().x,inputsprite->getPosition().y);
	      			}
	      			}
	      		  break;
	      	  case 4:
	      		for(int i=1;i<=4;i++)
	      			{
	      				if(i==1)
	      				{
	      					inputsprite=CCSprite::create("btn_input@2x.png");
	      					inputsprite->setPosition(ccp(solutionback->getPosition().x-(inputsprite->getContentSize().width/2*i)-4,solutionback->getPosition().y));
	      					this->addChild(inputsprite,5);
	      					input->addObject(inputsprite);
	      					fprintf(stderr,"\nx: %f and y:%f",inputsprite->getPosition().x,inputsprite->getPosition().y);
	      					inputsprite=CCSprite::create("btn_input@2x.png");
	      					inputsprite->setPosition(ccp(solutionback->getPosition().x+(inputsprite->getContentSize().width/2*i)+4,solutionback->getPosition().y));
	      					this->addChild(inputsprite,5);
	      					input->addObject(inputsprite);
	      					fprintf(stderr,"\nx: %f and y:%f",inputsprite->getPosition().x,inputsprite->getPosition().y);
	      				}
	      				if(i<=2&&i!=1)
	      				{
	      					inputsprite=CCSprite::create("btn_input@2x.png");
	      					inputsprite->setPosition(ccp(solutionback->getPosition().x-((inputsprite->getContentSize().width*i)-inputsprite->getContentSize().width/2)-4,solutionback->getPosition().y));
	      					this->addChild(inputsprite,5);
	      					input->addObject(inputsprite);
	      					fprintf(stderr,"\nx: %f and y:%f",inputsprite->getPosition().x,inputsprite->getPosition().y);
	      					inputsprite=CCSprite::create("btn_input@2x.png");
	      					inputsprite->setPosition(ccp(solutionback->getPosition().x+((inputsprite->getContentSize().width*i)-inputsprite->getContentSize().width/2)+4,solutionback->getPosition().y));
	      					this->addChild(inputsprite,5);
	      					input->addObject(inputsprite);
	      					fprintf(stderr,"\nx: %f and y:%f",inputsprite->getPosition().x,inputsprite->getPosition().y);
	      				}
	      			}
	      		break;





	      	  }	      	      	   	/////////////////type buttons//////////////////////////

	      	fprintf(stderr,"\nended1");   	   //char letters[12]={'K','O','R','E','A','T','E','A','S','H','G','S'};
	      	char letters[12]={query[index1].quer[0],query[index1].quer[1],query[index1].quer[2],query[index1].quer[3],query[index1].quer[4],query[index1].quer[5],query[index1].quer[6],query[index1].quer[7],query[index1].quer[8],query[index1].quer[9],query[index1].quer[10],query[index1].quer[11]};

	      	  	      		      	   //char *str=query[0].ans.basic_string;
	      	fprintf(stderr,"\nended2");

	      	  	      		      	  std::string s[13]={"k","0","r","e","t","e","a","s","h","g","s"};
	      	  	      		    for (unsigned i = 0; i < (sizeof(letters)-1); i++) {
	      	  	      		        unsigned j = rand() % sizeof(letters);
	      	  	      		        char tmp = letters[j];
	      	  	      		  letters[j] = letters[i];
	      	  	      	letters[i] = tmp;
	      	  	      		    }
	      	  	      		//    std::strcpy(st,letters);
	      	  	      		fprintf(stderr,"\nended3");
	      	  	 CCLabelTTF *letterss,*letterss1;
	      	  	 CCMenuItemLabel *label1,*label2;
	      	   CCMenuItemImage *letter,*letter1;
	      	   CCMenu *pmenu;
	      	   CCArray *lettersq=CCArray::createWithCapacity(12);
	      	 fprintf(stderr,"\nended4");
	      	 for(int i=0,j=6;i<6;i++,j++)
	      	 {

	      		 char a[2]={letters[i]};

	      		letter=CCMenuItemImage::create("btn_letter@2x.png","btn_letter@2x.png",this,menu_selector(HelloWorld::secletletter));
	      		// letter=CCSprite::create("btn_letter@2x.png");
	      		letter->setPosition(ccp(80+(i*(letter->getContentSize().width+8)),solutionback->getPosition().y-solutionback->getContentSize().height/2-letter->getContentSize().height/2-20));
	      		this->addChild(letter,5);
	      		letter->setTag(i+1);
	      		lettersq->addObject(letter);
	      		letterss=CCLabelTTF::create(strupr(a),"ARIAL",35.0);
	      		letterss->setPosition(ccp(80+(i*(letter->getContentSize().width+8)),solutionback->getPosition().y-solutionback->getContentSize().height/2-letter->getContentSize().height/2-20));
	      		letterss->setColor(ccc3(0,0,0));


	      		//label1=CCMenuItemLabel::create(letterss,this,menu_selector(HelloWorld::secletletter));
	      		//label1->setPosition(ccp(80+(i*(letter->getContentSize().width+8)),solutionback->getPosition().y-solutionback->getContentSize().height/2-letter->getContentSize().height/2-20));


	      		letterss->setTag(5000+letter->getTag());
	      		this->addChild(letterss,20);

	      		char b[2]={letters[j]};
	      		letter1=CCMenuItemImage::create("btn_letter@2x.png","btn_letter@2x.png",this,menu_selector(HelloWorld::secletletter));
	      		//letter1=CCSprite::create("btn_letter@2x.png");
	      		letter1->setPosition(ccp(80+(i*(letter1->getContentSize().width+8)),letter->getPosition().y-letter->getContentSize().height/2-letter1->getContentSize().height/2-20));
	      		letter1->setTag(j+1);
	      		this->addChild(letter1,5);
	      		lettersq->addObject(letter1);

	      		letterss1=CCLabelTTF::create(strupr(b),"ARIAL",35.0);
	      		letterss1->setPosition(ccp(80+(i*(letter1->getContentSize().width+8)),letter->getPosition().y-letter->getContentSize().height/2-letter1->getContentSize().height/2-20));
	      		letterss1->setColor(ccc3(0,0,0));
	      		letterss1->setTag(5000+letter1->getTag());
	      		this->addChild(letterss1,20);
	      		//label2=CCMenuItemLabel::create(letterss1,this,menu_selector(HelloWorld::secletletter));
	      		//label2->setPosition(ccp(80+(i*(letter1->getContentSize().width+8)),letter->getPosition().y-letter->getContentSize().height/2-letter1->getContentSize().height/2-20));




	      	 }
	      	 CCMenuItemImage *lastletter=CCMenuItemImage::create("btn_joker@2x.png","btn_joker@2x.png",this,menu_selector(HelloWorld::helper));
	      	 lastletter->setPosition(ccp(letter->getPosition().x+letter->getContentSize().width/2+7+lastletter->getContentSize().width/2,solutionback->getPosition().y-solutionback->getContentSize().height/2-lastletter->getContentSize().height/2-30));
	      	// this->addChild(lastletter,5);
	      	 pmenu=CCMenu::createWithArray(lettersq);
	      	 pmenu->setPosition(CCPointZero);

	      	 this->addChild(pmenu,5);
	      	 CCMenu* pMenu1 = CCMenu::create(backBtn,coinBtn,lastletter, NULL);
	      		      	       pMenu1->setPosition(CCPointZero);
	      		      	       this->addChild(pMenu1, 2);
	      		      	       fprintf(stderr,"\nended");

}


void HelloWorld::updt()
{
	if(levelicon1==1&&levelicon2==1&&levelicon3==1&&levelicon4==1&&levelicon5==1&&levelicon6==1&&levelicon7==1&&levelicon8==1&&levelicon9==1&&levelicon10==1&&levelicon11==1&&levelicon12==1&&levelicon13==1&&levelicon14==1&&levelicon15==1&&levelicon16==1&&levelicon17==1&&levelicon18==1&&levelicon19==1&&levelicon20==1&&levelicon21==1&&levelicon22==1&&levelicon23==1&&levelicon24==1&&levelicon25==1)
		{
			levelpack2unclock=1;

		}
		if(levelicon26==1&&levelicon27==1&&levelicon28==1&&levelicon29==1&&levelicon30==1&&levelicon31==1&&levelicon32==1&&levelicon33==1&&levelicon34==1&&levelicon35==1&&levelicon36==1&&levelicon37==1&&levelicon38==1&&levelicon39==1&&levelicon40==1&&levelicon41==1&&levelicon42==1&&levelicon43==1&&levelicon44==1&&levelicon45==1&&levelicon46==1&&levelicon47==1&&levelicon48==1&&levelicon49==1&&levelicon50==1)
			{
				levelpack3unclock=1;

			}
}

void HelloWorld::tick()
{
	unlocking=0;
	//levels=index1+1;
	if(lastval==4)
	{
	if(one==1&&two==1&&three==1&&four==1&&five==1)
	{


		if(xcount[0]==0&&xcount[1]==0&&xcount[2]==0&&xcount[3]==0&&xcount[4]==0)
		{

			fprintf(stderr,"\nsuccess");
			fprintf(stderr,"\n%d",levels);
			fprintf(stderr,"\n%d",index1);
			if(levels==1)///level 1
			{
				fprintf(stderr,"\nsuccess2");

				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon1!=1)
				{
					coinscnt+=20;
					progress1cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");

				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(402);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon1=1;
			}
			else if(levels==2)//level 2
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon2!=1)
				{
					coinscnt+=20;
					progress1cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(403);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon2=1;
			}
			else if(levels==8)//level 8
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon8!=1)
				{
					coinscnt+=20;
					progress1cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(409);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon8=1;
			}
			else if(levels==11)//level 11
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon11!=1)
				{
					coinscnt+=20;
					progress1cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(412);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon11=1;
			}
			else if(levels==15)//level 15
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon15!=1)
				{
					coinscnt+=20;
					progress1cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(416);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon15=1;
			}
			else if(levels==33)//level 33
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon33!=1)
				{
					coinscnt+=20;
					progress2cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(434);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon33=1;
			}
			else if(levels==40)//level 40
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon40!=1)
				{
					coinscnt+=20;
					progress2cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(441);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon40=1;
			}
			else if(levels==43)//level 43
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon43!=1)
				{
					coinscnt+=20;
					progress2cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(444);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon43=1;
			}
			else if(levels==49)//level 49
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon49!=1)
				{
					coinscnt+=20;
					progress2cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(450);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon49=1;
			}
			else if(levels==50)//level 50
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon50!=1)
				{
					coinscnt+=20;
					progress2cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::level2pack));
				unlocking=0;
				next->setTag(451);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon50=1;
			}
			else if(levels==51)//level 51
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon51!=1)
				{
					coinscnt+=20;
					progress3cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(452);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon51=1;
			}
			else if(levels==52)//level 52
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon52!=1)
				{
				coinscnt+=20;
				progress3cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(453);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon52=1;
			}
			else if(levels==57)//level 57
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon57!=1)
				{
				coinscnt+=20;
				progress3cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(458);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon57=1;
			}
			else if(levels==59)//level 59
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon59!=1)
				{
					coinscnt+=20;
					progress3cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(460);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon59=1;
			}
			else if(levels==62)//level 62
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon62!=1)
				{
					coinscnt+=20;
					progress3cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(463);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon62=1;
			}
			else if(levels==63)//level 63
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon63!=1)
				{
					coinscnt+=20;
					progress3cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(464);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon63=1;
			}
			else if(levels==67)//level 67
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon67!=1)
				{
					coinscnt+=20;
					progress3cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(468);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon67=1;
			}
			else if(levels==70)//level 70
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon70!=1)
				{
					coinscnt+=20;
					progress3cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(471);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon70=1;
			}

		}
		else
		{
			fprintf(stderr,"\nback");
			//sprite->runAction(CCMoveTo::create(0.4,ccp(x[4],y[4])));
			//fprintf(stderr,"\nx: %f and y: %f",x[4],y[4]);
			//sender->runAction(CCMoveTo::create(0.4,ccp(x[4],y[4])));
			fprintf(stderr,"\nback111");
			HelloWorld::moveback(lastimg,lastletter);
			//five=0;
		}

	}
	}

	else if(lastval==2)
	{
		if(one==1&&two==1&&three==1)
		{
			if(xcount[0]==0&&xcount[1]==0&&xcount[2]==0)
			{
				//SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				if(levels==3)////////level 3
				{
					CCSprite* win_level=CCSprite::create("back2.png");
					win_level->setPosition(ccp(size.width/2,size.height/2));
					this->addChild(win_level,10000);
					if(levelicon3!=1)
					{
						coinscnt+=20;
					progress1cnt++;
					}
					SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					unlocking=1;
					next->setTag(404);
					next->setPosition(ccp(size.width/2,size.height/2-70));
					CCMenu* next_level=CCMenu::create(next,NULL);
					next_level->setPosition(CCPointZero);
					this->addChild(next_level,10005);
					levelicon3=1;
				}
				else if(levels==5) //leve 5
				{
					CCSprite* win_level=CCSprite::create("back2.png");
					win_level->setPosition(ccp(size.width/2,size.height/2));
					this->addChild(win_level,10000);
					if(levelicon5!=1)
					{
						coinscnt+=20;
						progress1cnt++;
					}
					SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					unlocking=1;
					next->setTag(406);
					next->setPosition(ccp(size.width/2,size.height/2-70));
					CCMenu* next_level=CCMenu::create(next,NULL);
					next_level->setPosition(CCPointZero);
					this->addChild(next_level,10005);
					levelicon5=1;
				}
				else if(levels==30) //leve 30
				{
					CCSprite* win_level=CCSprite::create("back2.png");
					win_level->setPosition(ccp(size.width/2,size.height/2));
					this->addChild(win_level,10000);
					if(levelicon30!=1)
					{
						coinscnt+=20;
					progress2cnt++;
					}
					SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					unlocking=1;
					next->setTag(431);
					next->setPosition(ccp(size.width/2,size.height/2-70));
					CCMenu* next_level=CCMenu::create(next,NULL);
					next_level->setPosition(CCPointZero);
					this->addChild(next_level,10005);
					levelicon30=1;
				}
				else if(levels==42) //leve 42
				{
					CCSprite* win_level=CCSprite::create("back2.png");
					win_level->setPosition(ccp(size.width/2,size.height/2));
					this->addChild(win_level,10000);
					if(levelicon42!=1)
					{
						coinscnt+=20;
						progress2cnt++;
					}
					SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					unlocking=1;
					next->setTag(443);
					next->setPosition(ccp(size.width/2,size.height/2-70));
					CCMenu* next_level=CCMenu::create(next,NULL);
					next_level->setPosition(CCPointZero);
					this->addChild(next_level,10005);
					levelicon42=1;
				}

			}
			else
			{
				fprintf(stderr,"\nback");
				//sprite->runAction(CCMoveTo::create(0.4,ccp(x[4],y[4])));
				//fprintf(stderr,"\nx: %f and y: %f",x[4],y[4]);
				//sender->runAction(CCMoveTo::create(0.4,ccp(x[4],y[4])));
				fprintf(stderr,"\nback111");
				HelloWorld::moveback(lastimg,lastletter);
				//five=0;
			}

		}

	}

	else if(lastval==6)
	{
	if(one==1&&two==1&&three==1&&four==1&&five==1&&six==1&&seven==1)
	{

		if(xcount[0]==0&&xcount[1]==0&&xcount[2]==0&&xcount[3]==0&&xcount[4]==0&&xcount[5]==0&&xcount[6]==0)
		{
			//SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
			if(levels==4)//level   4
			{
			CCSprite* win_level=CCSprite::create("back2.png");
			win_level->setPosition(ccp(size.width/2,size.height/2));
			this->addChild(win_level,10000);
			if(levelicon4!=1)
			{
				coinscnt+=20;
				progress1cnt++;
			}
			SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
			CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
			unlocking=1;
			next->setTag(405);
			next->setPosition(ccp(size.width/2,size.height/2-70));
			CCMenu* next_level=CCMenu::create(next,NULL);
			next_level->setPosition(CCPointZero);
			this->addChild(next_level,10005);
			levelicon4=1;
			}

			else if(levels==9)//level  9
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon9!=1)
				{
					coinscnt+=20;
					progress1cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(410);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon9=1;
			}

			else if(levels==14)//level   14
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon14!=1)
				{
					coinscnt+=20;
					progress1cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(415);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon14=1;
			}

			else if(levels==17)//level   17
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon17!=1)
				{
					coinscnt+=20;
					progress1cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(418);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon17=1;
			}
			else if(levels==19)//level   19
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon19!=1)
				{
						coinscnt+=20;
					progress1cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(420);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon19=1;
			}
			else if(levels==20)//level   20
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon20!=1)
				{
					coinscnt+=20;
					progress1cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(421);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon20=1;
			}
			else if(levels==22)//level   22
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon22!=1)
				{
					coinscnt+=20;
					progress1cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(423);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon22=1;
			}
			else if(levels==26)//level   26
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon26!=1)
				{
					coinscnt+=20;
					progress2cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(427);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon26=1;
			}
			else if(levels==31)//level   31
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon31!=1)
				{
					coinscnt+=20;
					progress2cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(432);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon31=1;
			}
			else if(levels==36)//level   36
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon36!=1)
				{
					coinscnt+=20;
					progress2cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(437);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon36=1;
			}
			else if(levels==37)//level   37
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon37!=1)
				{
					coinscnt+=20;
					progress2cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(438);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon37=1;
			}
			else if(levels==39)//level   39
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon39!=1)
				{
					coinscnt+=20;
					progress2cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(440);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon39=1;
			}
			else if(levels==44)//level   44
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon44!=1)
				{
					coinscnt+=20;
					progress2cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(445);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon44=1;
			}
			else if(levels==58)//level   58
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon58!=1)
				{
					coinscnt+=20;
					progress3cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(459);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon58=1;
			}
			else if(levels==60)//level   60
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon60!=1)
				{
					coinscnt+=20;
					progress3cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(461);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon60=1;
			}
			else if(levels==64)//level  64
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon64!=1)
				{
					coinscnt+=20;
					progress3cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(465);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon64=1;
			}
			else if(levels==68)//level  68
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon68!=1)
				{
					coinscnt+=20;
					progress3cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(469);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon68=1;
			}
			else if(levels==71)//level  71
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon71!=1)
				{
					coinscnt+=20;
					progress3cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(472);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon71=1;
			}
			else if(levels==74)//level  74
			{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon74!=1)
				{
					coinscnt+=20;
					progress3cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(475);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon74=1;
			}
		}
		else
		{
			fprintf(stderr,"\nback");
			//sprite->runAction(CCMoveTo::create(0.4,ccp(x[4],y[4])));
			//fprintf(stderr,"\nx: %f and y: %f",x[4],y[4]);
			//sender->runAction(CCMoveTo::create(0.4,ccp(x[4],y[4])));
			fprintf(stderr,"\nback111");
			HelloWorld::moveback(lastimg,lastletter);
			//five=0;
		}

	}
}
	else if(lastval==5)
	{
		if(one==1&&two==1&&three==1&&four==1&&five==1&&six==1)
			{

				if(xcount[0]==0&&xcount[1]==0&&xcount[2]==0&&xcount[3]==0&&xcount[4]==0&&xcount[5]==0)
				{
					//SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					if(levels==6)//level  6
					{
					CCSprite* win_level=CCSprite::create("back2.png");
					win_level->setPosition(ccp(size.width/2,size.height/2));
					this->addChild(win_level,10000);
					if(levelicon6!=1)
					{
						coinscnt+=20;
					progress1cnt++;
					}
					SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					unlocking=1;
					next->setTag(407);
					next->setPosition(ccp(size.width/2,size.height/2-70));
					CCMenu* next_level=CCMenu::create(next,NULL);
					next_level->setPosition(CCPointZero);
					this->addChild(next_level,10005);
					levelicon6=1;
					}

					else if(levels==12)//level 12
					{
						CCSprite* win_level=CCSprite::create("back2.png");
						win_level->setPosition(ccp(size.width/2,size.height/2));
						this->addChild(win_level,10000);
						if(levelicon12!=1)
						{
							coinscnt+=20;
							progress1cnt++;
						}
						SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
						CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
						unlocking=1;
						next->setTag(413);
						next->setPosition(ccp(size.width/2,size.height/2-70));
						CCMenu* next_level=CCMenu::create(next,NULL);
						next_level->setPosition(CCPointZero);
						this->addChild(next_level,10005);
						levelicon12=1;
					}
					else if(levels==24)//level 24
					{
						CCSprite* win_level=CCSprite::create("back2.png");
						win_level->setPosition(ccp(size.width/2,size.height/2));
						this->addChild(win_level,10000);
						if(levelicon24!=1)
						{
					coinscnt+=20;
					progress1cnt++;
						}
						SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
						CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
						unlocking=1;
						next->setTag(425);
						next->setPosition(ccp(size.width/2,size.height/2-70));
						CCMenu* next_level=CCMenu::create(next,NULL);
						next_level->setPosition(CCPointZero);
						this->addChild(next_level,10005);
						levelicon24=1;
					}
					else if(levels==25)//level 25
						{
							CCSprite* win_level=CCSprite::create("back2.png");
							win_level->setPosition(ccp(size.width/2,size.height/2));
							this->addChild(win_level,10000);
								if(levelicon25!=1)
								{
									coinscnt+=20;
									progress1cnt++;
								}
								SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
							CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::level1pack));
							unlocking=0;
							next->setTag(426);
							next->setPosition(ccp(size.width/2,size.height/2-70));
							CCMenu* next_level=CCMenu::create(next,NULL);
							next_level->setPosition(CCPointZero);
							this->addChild(next_level,10005);
							levelicon25=1;
						}
					else if(levels==27)//level 27
					{
						CCSprite* win_level=CCSprite::create("back2.png");
						win_level->setPosition(ccp(size.width/2,size.height/2));
						this->addChild(win_level,10000);
						if(levelicon27!=1)
						{
							coinscnt+=20;
							progress2cnt++;
						}
						SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
						CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
						unlocking=1;
						next->setTag(428);
						next->setPosition(ccp(size.width/2,size.height/2-70));
						CCMenu* next_level=CCMenu::create(next,NULL);
						next_level->setPosition(CCPointZero);
						this->addChild(next_level,10005);
						levelicon27=1;
					}

				else if(levels==28)//level 28
				{
					CCSprite* win_level=CCSprite::create("back2.png");
					win_level->setPosition(ccp(size.width/2,size.height/2));
					this->addChild(win_level,10000);
					if(levelicon28!=1)
					{
						coinscnt+=20;
						progress2cnt++;
					}
					SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					unlocking=1;
					next->setTag(429);
					next->setPosition(ccp(size.width/2,size.height/2-70));
					CCMenu* next_level=CCMenu::create(next,NULL);
					next_level->setPosition(CCPointZero);
					this->addChild(next_level,10005);
					levelicon28=1;
				}
				else if(levels==32)//level 32
				{
					CCSprite* win_level=CCSprite::create("back2.png");
					win_level->setPosition(ccp(size.width/2,size.height/2));
					this->addChild(win_level,10000);
					if(levelicon32!=1)
					{
						coinscnt+=20;
						progress2cnt++;
					}
					SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					unlocking=1;
					next->setTag(433);
					next->setPosition(ccp(size.width/2,size.height/2-70));
					CCMenu* next_level=CCMenu::create(next,NULL);
					next_level->setPosition(CCPointZero);
					this->addChild(next_level,10005);
					levelicon32=1;
				}
				else if(levels==46)//level 46
				{
					CCSprite* win_level=CCSprite::create("back2.png");
					win_level->setPosition(ccp(size.width/2,size.height/2));
					this->addChild(win_level,10000);
					if(levelicon46!=1)
					{
						coinscnt+=20;
						progress2cnt++;
					}
					SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					unlocking=1;
					next->setTag(447);
					next->setPosition(ccp(size.width/2,size.height/2-70));
					CCMenu* next_level=CCMenu::create(next,NULL);
					next_level->setPosition(CCPointZero);
					this->addChild(next_level,10005);
					levelicon46=1;
				}
				else if(levels==47)//level 47
				{
					CCSprite* win_level=CCSprite::create("back2.png");
					win_level->setPosition(ccp(size.width/2,size.height/2));
					this->addChild(win_level,10000);
					if(levelicon47!=1)
					{
						coinscnt+=20;
						progress1cnt++;
					}
					SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					unlocking=1;
					next->setTag(448);
					next->setPosition(ccp(size.width/2,size.height/2-70));
					CCMenu* next_level=CCMenu::create(next,NULL);
					next_level->setPosition(CCPointZero);
					this->addChild(next_level,10005);
					levelicon47=1;
				}
				else if(levels==53)//level 53
				{
					CCSprite* win_level=CCSprite::create("back2.png");
					win_level->setPosition(ccp(size.width/2,size.height/2));
					this->addChild(win_level,10000);
					if(levelicon53!=1)
					{
						coinscnt+=20;
						progress3cnt++;
					}
					SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					unlocking=1;
					next->setTag(454);
					next->setPosition(ccp(size.width/2,size.height/2-70));
					CCMenu* next_level=CCMenu::create(next,NULL);
					next_level->setPosition(CCPointZero);
					this->addChild(next_level,10005);
					levelicon53=1;
				}
				else if(levels==66)//level 66
				{
					CCSprite* win_level=CCSprite::create("back2.png");
					win_level->setPosition(ccp(size.width/2,size.height/2));
					this->addChild(win_level,10000);
					if(levelicon66!=1)
					{
						coinscnt+=20;
						progress3cnt++;
					}
					SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					unlocking=1;
					next->setTag(467);
					next->setPosition(ccp(size.width/2,size.height/2-70));
					CCMenu* next_level=CCMenu::create(next,NULL);
					next_level->setPosition(CCPointZero);
					this->addChild(next_level,10005);
					levelicon66=1;
				}
				else if(levels==75)//level 75
				{
					CCSprite* win_level=CCSprite::create("back2.png");
					win_level->setPosition(ccp(size.width/2,size.height/2));
					this->addChild(win_level,10000);
					if(levelicon75!=1)
					{
						coinscnt+=20;
						progress3cnt++;
					}
					SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::mainscene));
					unlocking=0;
					//next->setTag(467);
					next->setPosition(ccp(size.width/2,size.height/2-70));
					CCMenu* next_level=CCMenu::create(next,NULL);
					next_level->setPosition(CCPointZero);
					this->addChild(next_level,10005);
					levelicon75=1;
				}
			}
				else
				{
					fprintf(stderr,"\nback");
					//sprite->runAction(CCMoveTo::create(0.4,ccp(x[4],y[4])));
					//fprintf(stderr,"\nx: %f and y: %f",x[4],y[4]);
					//sender->runAction(CCMoveTo::create(0.4,ccp(x[4],y[4])));
					fprintf(stderr,"\nback111");
					HelloWorld::moveback(lastimg,lastletter);
					//five=0;
				}

			}
	}

	else if(lastval==7)
		{
		if(one==1&&two==1&&three==1&&four==1&&five==1&&six==1&&seven==1&&eight==1)
		{

			if(xcount[0]==0&&xcount[1]==0&&xcount[2]==0&&xcount[3]==0&&xcount[4]==0&&xcount[5]==0&&xcount[6]==0&&xcount[7]==0)
			{
				//SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				if(levels==7)//level   7
				{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon7!=1)
				{
					coinscnt+=20;
					progress1cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(408);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon7=1;
				}
				else if(levels==10)//level   10
				{
				CCSprite* win_level=CCSprite::create("back2.png");
				win_level->setPosition(ccp(size.width/2,size.height/2));
				this->addChild(win_level,10000);
				if(levelicon10!=1)
				{
					coinscnt+=20;
					progress1cnt++;
				}
				SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
				unlocking=1;
				next->setTag(411);
				next->setPosition(ccp(size.width/2,size.height/2-70));
				CCMenu* next_level=CCMenu::create(next,NULL);
				next_level->setPosition(CCPointZero);
				this->addChild(next_level,10005);
				levelicon10=1;
				}
				else if(levels==21)//level   21
				{
					CCSprite* win_level=CCSprite::create("back2.png");
					win_level->setPosition(ccp(size.width/2,size.height/2));
					this->addChild(win_level,10000);
					if(levelicon21!=1)
					{
						coinscnt+=20;
						progress1cnt++;
					}
					SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					unlocking=1;
					next->setTag(422);
					next->setPosition(ccp(size.width/2,size.height/2-70));
					CCMenu* next_level=CCMenu::create(next,NULL);
					next_level->setPosition(CCPointZero);
					this->addChild(next_level,10005);
					levelicon21=1;
				}
				else if(levels==29)//level   29
				{
					CCSprite* win_level=CCSprite::create("back2.png");
					win_level->setPosition(ccp(size.width/2,size.height/2));
					this->addChild(win_level,10000);
					if(levelicon29!=1)
					{
						coinscnt+=20;
						progress2cnt++;
					}
					SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					unlocking=1;
					next->setTag(430);
					next->setPosition(ccp(size.width/2,size.height/2-70));
					CCMenu* next_level=CCMenu::create(next,NULL);
					next_level->setPosition(CCPointZero);
					this->addChild(next_level,10005);
					levelicon29=1;
				}
				else if(levels==41)//level   41
				{
					CCSprite* win_level=CCSprite::create("back2.png");
					win_level->setPosition(ccp(size.width/2,size.height/2));
					this->addChild(win_level,10000);
					if(levelicon41!=1)
					{
						coinscnt+=20;
						progress2cnt++;
					}
					SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					unlocking=1;
					next->setTag(442);
					next->setPosition(ccp(size.width/2,size.height/2-70));
					CCMenu* next_level=CCMenu::create(next,NULL);
					next_level->setPosition(CCPointZero);
					this->addChild(next_level,10005);
					levelicon41=1;
				}
				else if(levels==45)//level  45
				{
					CCSprite* win_level=CCSprite::create("back2.png");
					win_level->setPosition(ccp(size.width/2,size.height/2));
					this->addChild(win_level,10000);
					if(levelicon45!=1)
					{
						coinscnt+=20;
						progress2cnt++;
					}
					SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					unlocking=1;
					next->setTag(446);
					next->setPosition(ccp(size.width/2,size.height/2-70));
					CCMenu* next_level=CCMenu::create(next,NULL);
					next_level->setPosition(CCPointZero);
					this->addChild(next_level,10005);
					levelicon45=1;
				}
				else if(levels==55)//level  55
				{
					CCSprite* win_level=CCSprite::create("back2.png");
					win_level->setPosition(ccp(size.width/2,size.height/2));
					this->addChild(win_level,10000);
					if(levelicon55!=1)
					{
						coinscnt+=20;
						progress3cnt++;
					}
					SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					unlocking=1;
					next->setTag(456);
					next->setPosition(ccp(size.width/2,size.height/2-70));
					CCMenu* next_level=CCMenu::create(next,NULL);
					next_level->setPosition(CCPointZero);
					this->addChild(next_level,10005);
					levelicon55=1;
				}
				else if(levels==61)//level  61
				{
					CCSprite* win_level=CCSprite::create("back2.png");
					win_level->setPosition(ccp(size.width/2,size.height/2));
					this->addChild(win_level,10000);
					if(levelicon61!=1)
					{
						coinscnt+=20;
						progress3cnt++;
					}
					SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					unlocking=1;
					next->setTag(462);
					next->setPosition(ccp(size.width/2,size.height/2-70));
					CCMenu* next_level=CCMenu::create(next,NULL);
					next_level->setPosition(CCPointZero);
					this->addChild(next_level,10005);
					levelicon61=1;
				}
				else if(levels==69)//level  69
				{
					CCSprite* win_level=CCSprite::create("back2.png");
					win_level->setPosition(ccp(size.width/2,size.height/2));
					this->addChild(win_level,10000);
					if(levelicon69!=1)
					{
						coinscnt+=20;
						progress3cnt++;
					}
					SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					unlocking=1;
					next->setTag(470);
					next->setPosition(ccp(size.width/2,size.height/2-70));
					CCMenu* next_level=CCMenu::create(next,NULL);
					next_level->setPosition(CCPointZero);
					this->addChild(next_level,10005);
					levelicon69=1;
				}
				else if(levels==72)//level  72
				{
					CCSprite* win_level=CCSprite::create("back2.png");
					win_level->setPosition(ccp(size.width/2,size.height/2));
					this->addChild(win_level,10000);
					if(levelicon72!=1)
					{
						coinscnt+=20;
						progress3cnt++;
					}
					SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					unlocking=1;
					next->setTag(473);
					next->setPosition(ccp(size.width/2,size.height/2-70));
					CCMenu* next_level=CCMenu::create(next,NULL);
					next_level->setPosition(CCPointZero);
					this->addChild(next_level,10005);
					levelicon72=1;
				}
				else if(levels==73)//level  73
				{
					CCSprite* win_level=CCSprite::create("back2.png");
					win_level->setPosition(ccp(size.width/2,size.height/2));
					this->addChild(win_level,10000);
					if(levelicon73!=1)
					{
						coinscnt+=20;
						progress3cnt++;
					}
					SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					unlocking=1;
					next->setTag(474);
					next->setPosition(ccp(size.width/2,size.height/2-70));
					CCMenu* next_level=CCMenu::create(next,NULL);
					next_level->setPosition(CCPointZero);
					this->addChild(next_level,10005);
					levelicon73=1;
				}
			}
			else
			{
				fprintf(stderr,"\nback");
				//sprite->runAction(CCMoveTo::create(0.4,ccp(x[4],y[4])));
				//fprintf(stderr,"\nx: %f and y: %f",x[4],y[4]);
				//sender->runAction(CCMoveTo::create(0.4,ccp(x[4],y[4])));
				fprintf(stderr,"\nback111");
				HelloWorld::moveback(lastimg,lastletter);
				//five=0;
			}

		}
	}
	else if(lastval==3)
	{
		  if(one==1&&two==1&&three==1&&four==1)
		  {
			  if(xcount[0]==0&&xcount[1]==0&&xcount[2]==0&&xcount[3]==0)
			  {
				  //SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
				  if(levels==13)//level 13
				  {
					  CCSprite* win_level=CCSprite::create("back2.png");
					  win_level->setPosition(ccp(size.width/2,size.height/2));
					  this->addChild(win_level,10000);
					  if(levelicon13!=1)
					  {
						  coinscnt+=20;
						  progress1cnt++;
					  }
					  SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					  CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					  unlocking=1;
					  next->setTag(414);
					  next->setPosition(ccp(size.width/2,size.height/2-70));
					  CCMenu* next_level=CCMenu::create(next,NULL);
					  next_level->setPosition(CCPointZero);
					  this->addChild(next_level,10005);
					  levelicon13=1;
				  }
				  else if(levels==16)//level 16
				  {
					  CCSprite* win_level=CCSprite::create("back2.png");
					  win_level->setPosition(ccp(size.width/2,size.height/2));
					  this->addChild(win_level,10000);
					  if(levelicon16!=1)
					  {
						  coinscnt+=20;
						  progress1cnt++;
					  }
					  SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					  CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					  unlocking=1;
					  next->setTag(417);
					  next->setPosition(ccp(size.width/2,size.height/2-70));
					  CCMenu* next_level=CCMenu::create(next,NULL);
					  next_level->setPosition(CCPointZero);
					  this->addChild(next_level,10005);
					  levelicon16=1;
				  }
				  else if(levels==18)//level 18
				  {
					  CCSprite* win_level=CCSprite::create("back2.png");
					  win_level->setPosition(ccp(size.width/2,size.height/2));
					  this->addChild(win_level,10000);
					  if(levelicon18!=1)
					  {
						  coinscnt+=20;
						  progress1cnt++;
					  }
					  SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					  CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					  unlocking=1;
					  next->setTag(419);
					  next->setPosition(ccp(size.width/2,size.height/2-70));
					  CCMenu* next_level=CCMenu::create(next,NULL);
					  next_level->setPosition(CCPointZero);
					  this->addChild(next_level,10005);
					  levelicon18=1;
				  }
				  else if(levels==23)//level 23
				  {
					  CCSprite* win_level=CCSprite::create("back2.png");
					  win_level->setPosition(ccp(size.width/2,size.height/2));
					  this->addChild(win_level,10000);
					  	  if(levelicon23!=1)
					  	  {
					  		  coinscnt+=20;
					  		  progress1cnt++;
					  	  }
					  	SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					  CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					  unlocking=1;
					  next->setTag(424);
					  next->setPosition(ccp(size.width/2,size.height/2-70));
					  CCMenu* next_level=CCMenu::create(next,NULL);
					  next_level->setPosition(CCPointZero);
					  this->addChild(next_level,10005);
					  levelicon23=1;
				  }
				  else if(levels==34)//level 34
				  {
					  CCSprite* win_level=CCSprite::create("back2.png");
					  win_level->setPosition(ccp(size.width/2,size.height/2));
					  this->addChild(win_level,10000);
					  if(levelicon34!=1)
					  {
						  coinscnt+=20;
						  progress2cnt++;
					  }
					  SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					  CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					  unlocking=1;
					  next->setTag(435);
					  next->setPosition(ccp(size.width/2,size.height/2-70));
					  CCMenu* next_level=CCMenu::create(next,NULL);
					  next_level->setPosition(CCPointZero);
					  this->addChild(next_level,10005);
					  levelicon34=1;
				  }
				  else if(levels==35)//level 35
				  {
					  CCSprite* win_level=CCSprite::create("back2.png");
					  win_level->setPosition(ccp(size.width/2,size.height/2));
					  this->addChild(win_level,10000);
					  if(levelicon35!=1)
					  {
						  coinscnt+=20;
						  progress2cnt++;
					  }
					  SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					  CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					  unlocking=1;
					  next->setTag(436);
					  next->setPosition(ccp(size.width/2,size.height/2-70));
					  CCMenu* next_level=CCMenu::create(next,NULL);
					  next_level->setPosition(CCPointZero);
					  this->addChild(next_level,10005);
					  levelicon35=1;
				  }
				  else if(levels==38)//level 38
				  {
					  CCSprite* win_level=CCSprite::create("back2.png");
					  win_level->setPosition(ccp(size.width/2,size.height/2));
					  this->addChild(win_level,10000);
					  if(levelicon38!=1)
					  {
						  coinscnt+=20;
						  progress2cnt++;
					  }
					  SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					  CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					  unlocking=1;
					  next->setTag(439);
					  next->setPosition(ccp(size.width/2,size.height/2-70));
					  CCMenu* next_level=CCMenu::create(next,NULL);
					  next_level->setPosition(CCPointZero);
					  this->addChild(next_level,10005);
					  levelicon38=1;
				  }
				  else if(levels==48)//level 48
				  {
					  CCSprite* win_level=CCSprite::create("back2.png");
					  win_level->setPosition(ccp(size.width/2,size.height/2));
					  this->addChild(win_level,10000);
					  if(levelicon48!=1)
					  {
						  coinscnt+=20;
						  progress2cnt++;
					  }
					  SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					  CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					  unlocking=1;
					  next->setTag(450);
					  next->setPosition(ccp(size.width/2,size.height/2-70));
					  CCMenu* next_level=CCMenu::create(next,NULL);
					  next_level->setPosition(CCPointZero);
					  this->addChild(next_level,10005);
					  levelicon48=1;
				  }
				  else if(levels==54)//level 54
				  {
					  CCSprite* win_level=CCSprite::create("back2.png");
					  win_level->setPosition(ccp(size.width/2,size.height/2));
					  this->addChild(win_level,10000);
					  if(levelicon54!=1)
					  {
						  coinscnt+=20;
						  progress3cnt++;
					  }
					  SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					  CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					  unlocking=1;
					  next->setTag(455);
					  next->setPosition(ccp(size.width/2,size.height/2-70));
					  CCMenu* next_level=CCMenu::create(next,NULL);
					  next_level->setPosition(CCPointZero);
					  this->addChild(next_level,10005);
					  levelicon54=1;
				  }
				 else if(levels==56)//level 56
				 {
					 CCSprite* win_level=CCSprite::create("back2.png");
					 win_level->setPosition(ccp(size.width/2,size.height/2));
					 this->addChild(win_level,10000);
					 if(levelicon56!=1)
					 {
						 coinscnt+=20;
						 progress3cnt++;
					 }
					 SimpleAudioEngine::sharedEngine()->playEffect("success.wav");
					 CCMenuItemImage* next=CCMenuItemImage::create("nextlevel1.png","nextlevel2.png",this,menu_selector(HelloWorld::deff));
					 unlocking=1;
					 next->setTag(457);
					 next->setPosition(ccp(size.width/2,size.height/2-70));
					 CCMenu* next_level=CCMenu::create(next,NULL);
					 next_level->setPosition(CCPointZero);
					 this->addChild(next_level,10005);
					 levelicon56=1;
				 }
			  }
			  else
			  			{
			  				fprintf(stderr,"\nback");
			  				//sprite->runAction(CCMoveTo::create(0.4,ccp(x[4],y[4])));
			  				//fprintf(stderr,"\nx: %f and y: %f",x[4],y[4]);
			  				//sender->runAction(CCMoveTo::create(0.4,ccp(x[4],y[4])));
			  				fprintf(stderr,"\nback111");
			  				HelloWorld::moveback(lastimg,lastletter);
			  				//five=0;
			  			}

		  }
}
}
void HelloWorld::moveback(CCNode *lastimg,CCNode *lastletter)
{
	ccColor3B col=solutionback->getColor();
	unlocking=1;

	CCActionInterval *red=CCTintTo::create(0.2,255,0,0);
	SimpleAudioEngine::sharedEngine()->playEffect("fail.wav");
	CCActionInterval *rev=CCTintTo::create(0.1,col.r,col.g,col.b);
	red->setTag(1111111);
	solutionback->runAction(CCSequence::create(red,rev,NULL));
if(reveallast==0)
{
	lastletter->runAction(CCMoveTo::create(0.4,ccp(x[lastval],y[lastval])));
	fprintf(stderr,"\nx: %f and y: %f",x[lastval],y[lastval]);
	lastimg->runAction(CCSequence::create(CCMoveTo::create(0.4,ccp(x[lastval],y[lastval])),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::ulev)),NULL));
			if(lastval==4)
			{
					five=0;
			}
			else if(lastval==2)
			{
				three=0;
			}
			else if(lastval==6)
			{
			seven=0;
			}
			else if(lastval==5)
			{
				six=0;
			}
			else if(lastval==7)
			{
				eight=0;
			}
			else if(lastval==3)
			{
				four=0;
			}
}
			//solutionback->stopAction()();
}

void HelloWorld::ulev()
{
	unlocking=0;
}

void HelloWorld::secletletter(CCNode *sender)
{
	if(unlocking==0)
	{

	unlocking=1;
	SimpleAudioEngine::sharedEngine()->playEffect("letter_tap.wav");
	SimpleAudioEngine::sharedEngine()->setEffectsVolume(1.0);

	CCLabelTTF *sprite=dynamic_cast<CCLabelTTF*>(this->getChildByTag(5000+sender->getTag()));
		CCObject* it = NULL;



		float xposition=sender->getPosition().x;

switch(query[index1].ans.length())
{


case 5:
{
	const char* cmp[5];
				    const char* answer_check[5];

				    std::string answer[5];
				    for(int b=0;b<query[index1].ans.length();b++)
				    {
				    	answer[b]=query[index1].ans[b];
				    }
				    for(int g=0;g<5;g++)
				    {
				    	answer_check[g]=answer[g].c_str();
				    }
	float xpoints[5]={209,293,384,475,559};
	if(xposition!=209&&xposition!=293&&xposition!=384&&xposition!=475&&xposition!=559)
		{


			if(one==0)
			{
				count=0;
				x[count]=sender->getPosition().x;
						y[count]=sender->getPosition().y;
				sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[0],432)));
				lastval=4;
				one=1;
				const char *a=sprite->getString();
								cmp[0]=a;
								xcount[0]=stricmp(cmp[0],answer_check[0]);
				//sender->runAction(CCMoveTo::create(0.05,ccp(xpoints[0],432)));
				sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[0],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));
				fprintf(stderr,"\nx:---%f,,y=---%f",x[count],y[count]);



			}
			else if(two==0)
			{
				count=1;
							x[count]=sender->getPosition().x;
									y[count]=sender->getPosition().y;
				sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[1],432)));
				lastval=4;
							//sender->runAction(CCMoveTo::create(0.05,ccp(xpoints[1],432)));
				two=1;
				const char *a=sprite->getString();
											cmp[1]=a;
											xcount[1]=stricmp(cmp[1],answer_check[1]);

				sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[1],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));



			}
			else if(three==0)
					{
				count=2;
							x[count]=sender->getPosition().x;
									y[count]=sender->getPosition().y;
						sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[2],432)));
						lastval=4;
						three=1;
						const char *a=sprite->getString();
															cmp[2]=a;

															xcount[2]=stricmp(cmp[2],answer_check[2]);

									//sender->runAction(CCMoveTo::create(0.05,ccp(xpoints[2],432)));
						sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[2],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));


					}
			else if(four==0)
					{
				count=3;
							x[count]=sender->getPosition().x;
									y[count]=sender->getPosition().y;
						sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[3],432)));
						lastval=4;
						four=1;
						const char *a=sprite->getString();
															cmp[3]=a;
															xcount[3]=stricmp(cmp[3],answer_check[3]);

									//sender->runAction(CCMoveTo::create(0.05,ccp(xpoints[3],432)));
						sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[3],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));

					}
			else if(five==0)
					{
				count=4;
							x[count]=sender->getPosition().x;
									y[count]=sender->getPosition().y;
									const char *a=sprite->getString();
																	cmp[4]=a;
																	xcount[4]=stricmp(cmp[4],answer_check[4]);
																	five=1;
																	lastval=4;
						sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[4],432)));
									sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[4],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));
									lastimg=dynamic_cast<CCMenuItemImage *> (sender);
									lastletter=dynamic_cast<CCLabelTTF *> (sprite);

									//this->schedule(schedule_selector(HelloWorld::tick));



					}

		}
		else
		{
			int dest;
			unlocking=1;
			float rmposition=sender->getPosition().x;
			for(int i=0;i<5;i++)
			{
				if(rmposition==xpoints[i])
				{
					 dest=i;

				}
			}
			fprintf(stderr,"x:%f  y:%f",x[dest],y[dest]);
			sprite->runAction(CCMoveTo::create(0.05,ccp(x[dest],y[dest])));
			sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(x[dest],y[dest])),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::ulev)),NULL));

											if(dest==0)
											{
												one=0;
											}
											else if(dest==1)
											{
												two=0;
											}
											else if(dest==2)
											{
												three=0;
											}
											else if(dest==3)
											{
												four=0;
											}
											else if(dest==4)
											{
												five=0;
											}
		}
}
				break;
case 3:
{
	const char* cmp[3];
				    const char* answer_check[3];

				    std::string answer[3];
				    for(int b=0;b<query[index1].ans.length();b++)
				    {
				    	answer[b]=query[index1].ans[b];
				    }
				    for(int g=0;g<3;g++)
				    {
				    	answer_check[g]=answer[g].c_str();
				    }
	float xpoints[3]={293,384,475};
	if(xposition!=293&&xposition!=384&&xposition!=475)
			{


				if(one==0)
				{
					count=0;
					x[count]=sender->getPosition().x;
							y[count]=sender->getPosition().y;
							one=1;
					sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[0],432)));
					lastval=2;
					sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[0],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));

					//sender->runAction(CCMoveTo::create(0.05,ccp(xpoints[0],432)));
					fprintf(stderr,"\nx:---%f,,y=---%f",x[count],y[count]);
					const char *a=sprite->getString();
					cmp[0]=a;
					xcount[0]=stricmp(cmp[0],answer_check[0]);


				}
				else if(two==0)
				{
					count=1;
								x[count]=sender->getPosition().x;
										y[count]=sender->getPosition().y;
										two=1;
					sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[1],432)));
							//	sender->runAction(CCMoveTo::create(0.05,ccp(xpoints[1],432)));
					lastval=2;
					sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[1],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));

								const char *a=sprite->getString();
								cmp[1]=a;
								xcount[1]=stricmp(cmp[1],answer_check[1]);

				}

				else if(three==0)
						{
					count=2;
								x[count]=sender->getPosition().x;
										y[count]=sender->getPosition().y;
										const char *a=sprite->getString();
																		cmp[2]=a;
																		xcount[2]=stricmp(cmp[2],answer_check[2]);
																		three=1;
																		lastval=2;
							sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[2],432)));
										sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[2],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));
										lastimg=dynamic_cast<CCMenuItemImage *> (sender);
										lastletter=dynamic_cast<CCLabelTTF *> (sprite);

										//this->schedule(schedule_selector(HelloWorld::tick));



						}

			}
			else
			{
				int dest;
				float rmposition=sender->getPosition().x;
				for(int i=0;i<3;i++)
				{
					if(rmposition==xpoints[i])
					{
						 dest=i;

					}
				}
				fprintf(stderr,"x:%f  y:%f",x[dest],y[dest]);
				sprite->runAction(CCMoveTo::create(0.05,ccp(x[dest],y[dest])));
				//sender->runAction(CCMoveTo::create(0.05,ccp(x[dest],y[dest])));
				sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(x[dest],y[dest])),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::ulev)),NULL));
												if(dest==0)
												{
													one=0;
												}
												else if(dest==1)
												{
													two=0;
												}
												else if(dest==2)
												{
													three=0;
												}


			}
}
	break;
case 4:
{
	const char* cmp[4];
				    const char* answer_check[4];

				    std::string answer[4];
				    for(int b=0;b<query[index1].ans.length();b++)
				    {
				    	answer[b]=query[index1].ans[b];
				    }
				    for(int g=0;g<4;g++)
				    {
				    	answer_check[g]=answer[g].c_str();
				    }
	float xpoints[4]={254,338,430,514};
	if(xposition!=254&&xposition!=338&&xposition!=430&&xposition!=514)
	{
	if(one==0)
	{
	count=0;
	x[count]=sender->getPosition().x;
	y[count]=sender->getPosition().y;
	one=1;
	lastval=3;
	sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[0],432)));
	sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[0],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));
	//sender->runAction(CCMoveTo::create(0.05,ccp(xpoints[0],432)));
	fprintf(stderr,"\nx:---%f,,y=---%f",x[count],y[count]);
	const char *a=sprite->getString();
	cmp[0]=a;
	xcount[0]=stricmp(cmp[0],answer_check[0]);

	}
	else if(two==0)
	{
	count=1;
	x[count]=sender->getPosition().x;
	y[count]=sender->getPosition().y;
	two=1;
	sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[1],432)));
	lastval=3;
	sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[1],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));
	//sender->runAction(CCMoveTo::create(0.05,ccp(xpoints[1],432)));
		const char *a=sprite->getString();
	cmp[1]=a;
	xcount[1]=stricmp(cmp[1],answer_check[1]);
	}
	else if(three==0)
	{
	count=2;
	x[count]=sender->getPosition().x;
	y[count]=sender->getPosition().y;
	three=1;
	sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[2],432)));
	lastval=3;
	sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[2],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));

	//sender->runAction(CCMoveTo::create(0.05,ccp(xpoints[2],432)));
	const char *a=sprite->getString();
	cmp[2]=a;
	xcount[2]=stricmp(cmp[2],answer_check[2]);

	}
	else if(four==0)
	{
	count=3;
	x[count]=sender->getPosition().x;
	y[count]=sender->getPosition().y;
	const char *a=sprite->getString();
	cmp[3]=a;
	xcount[3]=stricmp(cmp[3],answer_check[3]);
	four=1;
	lastval=3;
	sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[3],432)));
	sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[3],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));
	lastimg=dynamic_cast<CCMenuItemImage *> (sender);
	lastletter=dynamic_cast<CCLabelTTF *> (sprite);
	//this->schedule(schedule_selector(HelloWorld::tick));
	}
	}
	else
	{
	int dest;
	float rmposition=sender->getPosition().x;
	for(int i=0;i<4;i++)
	{
	if(rmposition==xpoints[i])
	{
	dest=i;
	}
	}
	fprintf(stderr,"x:%f  y:%f",x[dest],y[dest]);
	sprite->runAction(CCMoveTo::create(0.05,ccp(x[dest],y[dest])));
	//sender->runAction(CCMoveTo::create(0.05,ccp(x[dest],y[dest])));
	sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(x[dest],y[dest])),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::ulev)),NULL));
	if(dest==0)
	{
	one=0;
	}
	else if(dest==1)
	{
	two=0;
	}
	else if(dest==2)
	{
	three=0;
	}
	else if(dest==3)
	{
	four=0;
	}
	}}
break;

case 6:
{
	const char* cmp[6];
				    const char* answer_check[6];

				    std::string answer[6];
				    for(int b=0;b<query[index1].ans.length();b++)
				    {
				    	answer[b]=query[index1].ans[b];
				    }
				    for(int g=0;g<6;g++)
				    {
				    	answer_check[g]=answer[g].c_str();
				    }
	float xpoints[6]={170,254,338,430,514,588};
	if(xposition!=170&&xposition!=254&&xposition!=338&&xposition!=430&&xposition!=514&&xposition!=588)
				{


					if(one==0)
					{
						count=0;
						x[count]=sender->getPosition().x;
								y[count]=sender->getPosition().y;
								one=1;lastval=5;
						sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[0],432)));
						sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[0],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));
						//sender->runAction(CCMoveTo::create(0.05,ccp(xpoints[0],432)));
						fprintf(stderr,"\nx:---%f,,y=---%f",x[count],y[count]);
						const char *a=sprite->getString();
						cmp[0]=a;
						xcount[0]=stricmp(cmp[0],answer_check[0]);


					}
					else if(two==0)
					{
						count=1;
									x[count]=sender->getPosition().x;
											y[count]=sender->getPosition().y;
											two=1;lastval=5;
						sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[1],432)));
						sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[1],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));
						//				sender->runAction(CCMoveTo::create(0.05,ccp(xpoints[1],432)));


									const char *a=sprite->getString();
									cmp[1]=a;
									xcount[1]=stricmp(cmp[1],answer_check[1]);

					}

					else if(three==0)
							{
						count=2;
									x[count]=sender->getPosition().x;
											y[count]=sender->getPosition().y;
											three=1;lastval=5;
											sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[2],432)));
											sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[2],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));
											//													sender->runAction(CCMoveTo::create(0.05,ccp(xpoints[2],432)));

											const char *a=sprite->getString();
																			cmp[2]=a;
																			xcount[2]=stricmp(cmp[2],answer_check[2]);

							}
					else if(four==0)
					{
						count=3;
															x[count]=sender->getPosition().x;
																	y[count]=sender->getPosition().y;
																	four=1;
																	lastval=5;
																	sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[3],432)));
																	sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[3],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));
																	//															sender->runAction(CCMoveTo::create(0.05,ccp(xpoints[3],432)));

																	const char *a=sprite->getString();
																									cmp[3]=a;
																									xcount[3]=stricmp(cmp[3],answer_check[3]);


					}
					else if(five==0)
					{

						count=4;
															x[count]=sender->getPosition().x;
																	y[count]=sender->getPosition().y;
																	five=1;
																	sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[4],432)));
																	lastval=5;
																	sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[4],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));
																	//										sender->runAction(CCMoveTo::create(0.05,ccp(xpoints[4],432)));

																	const char *a=sprite->getString();
																									cmp[4]=a;
																									xcount[4]=stricmp(cmp[4],answer_check[4]);






					}
					else if(six==0)
					{
						count=5;
						x[count]=sender->getPosition().x;
						y[count]=sender->getPosition().y;
						const char *a=sprite->getString();
						cmp[5]=a;
						xcount[5]=stricmp(cmp[5],answer_check[5]);
						six=1;
						       lastval=5;
								sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[5],432)));
											sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[5],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));
											lastimg=dynamic_cast<CCMenuItemImage *> (sender);
											lastletter=dynamic_cast<CCLabelTTF *> (sprite);

											//this->schedule(schedule_selector(HelloWorld::tick));
							}
				}
				else
				{
					int dest;
					float rmposition=sender->getPosition().x;
					for(int i=0;i<6;i++)
					{
						if(rmposition==xpoints[i])
						{
							 dest=i;

						}
					}
					fprintf(stderr,"x:%f  y:%f",x[dest],y[dest]);
					sprite->runAction(CCMoveTo::create(0.05,ccp(x[dest],y[dest])));
					//sender->runAction(CCMoveTo::create(0.05,ccp(x[dest],y[dest])));
					sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(x[dest],y[dest])),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::ulev)),NULL));
					if(dest==0)
					{
						one=0;
					}
					else if(dest==1)
					{
						two=0;
					}
					else if(dest==2)
					{
						three=0;
					}
					else if(dest==3)
					{
					      four=0;
					}
					else if(dest==4)
					{
					      five=0;
					}
					else if(dest==5)
					{
						six=0;
					}

				}


}
break;
case 7:
{
	const char* cmp[7];
				    const char* answer_check[7];

				    std::string answer[7];
				    for(int b=0;b<query[index1].ans.length();b++)
				    {
				    	answer[b]=query[index1].ans[b];
				    }
				    for(int g=0;g<7;g++)
				    {
				    	answer_check[g]=answer[g].c_str();
				    }
	float xpoints[7]={125,209,293,384,475,559,643};
	if(xposition!=125&&xposition!=209&&xposition!=293&&xposition!=384&&xposition!=475&&xposition!=559&&xposition!=643)
			{


				if(one==0)
				{
					count=0;
					x[count]=sender->getPosition().x;
							y[count]=sender->getPosition().y;one=1;
					sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[0],432)));
					lastval=6;
					sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[0],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));
					//sender->runAction(CCMoveTo::create(0.05,ccp(xpoints[0],432)));
					fprintf(stderr,"\nx:---%f,,y=---%f",x[0],y[0]);
					const char *a=sprite->getString();
					cmp[0]=a;
					xcount[0]=stricmp(cmp[0],answer_check[0]);


				}
				else if(two==0)
				{
					count=1;
								x[count]=sender->getPosition().x;
										y[count]=sender->getPosition().y;two=1;
					sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[1],432)));
					lastval=6;
					sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[1],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));
							//	sender->runAction(CCMoveTo::create(0.05,ccp(xpoints[1],432)));


								const char *a=sprite->getString();
								cmp[1]=a;
								xcount[1]=stricmp(cmp[1],answer_check[1]);

				}
				else if(three==0)
						{
					count=2;
								x[2]=sender->getPosition().x;
										y[2]=sender->getPosition().y;three=1;
							sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[2],432)));
							lastval=6;
							sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[2],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));
							//		sender->runAction(CCMoveTo::create(0.05,ccp(xpoints[2],432)));
										const char *a=sprite->getString();
										cmp[2]=a;
										xcount[2]=stricmp(cmp[2],answer_check[2]);


						}
				else if(four==0)
						{
					count=3;
								x[count]=sender->getPosition().x;
										y[count]=sender->getPosition().y;four=1;
							sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[3],432)));
							lastval=6;
							sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[3],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));
									//	sender->runAction(CCMoveTo::create(0.05,ccp(xpoints[3],432)));
										const char *a=sprite->getString();
										cmp[3]=a;
										xcount[3]=stricmp(cmp[3],answer_check[3]);

						}
				else if(five==0)
				{
					count=4;
					x[4]=sender->getPosition().x;
					y[4]=sender->getPosition().y;five=1;
					sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[4],432)));
					lastval=6;
					sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[4],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));
					//sender->runAction(CCMoveTo::create(0.05,ccp(xpoints[4],432)));
					const char *a=sprite->getString();
					cmp[4]=a;
					xcount[4]=stricmp(cmp[4],answer_check[4]);

				}
				else if(six==0)
								{
									count=5;
									x[5]=sender->getPosition().x;
									y[5]=sender->getPosition().y;six=1;
									sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[5],432)));
									lastval=6;
									sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[5],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));
									//	sender->runAction(CCMoveTo::create(0.05,ccp(xpoints[5],432)));
									const char *a=sprite->getString();
									cmp[5]=a;
									xcount[5]=stricmp(cmp[5],answer_check[5]);

								}
				else if(seven==0)
						{
					count=6;
								x[6]=sender->getPosition().x;
										y[6]=sender->getPosition().y;
										const char *a=sprite->getString();
											cmp[6]=a;
											xcount[6]=stricmp(cmp[6],answer_check[6]);
											seven=1;
											lastval=6;
							sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[6],432)));

										lastimg=dynamic_cast<CCMenuItemImage *> (sender);
										lastletter=dynamic_cast<CCLabelTTF *> (sprite);
										sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[6],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));
										//this->schedule(schedule_selector(HelloWorld::tick));



						}

			}
			else
			{
				int dest;
				float rmposition=sender->getPosition().x;
				for(int i=0;i<7;i++)
				{
					if(rmposition==xpoints[i])
					{
						 dest=i;

					}
				}
				fprintf(stderr,"x:%f  y:%f",x[dest],y[dest]);
				sprite->runAction(CCMoveTo::create(0.05,ccp(x[dest],y[dest])));
				//sender->runAction(CCMoveTo::create(0.05,ccp(x[dest],y[dest])));
				sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(x[dest],y[dest])),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::ulev)),NULL));
												if(dest==0)
												{
													one=0;
												}
												else if(dest==1)
												{
													two=0;
												}
												else if(dest==2)
												{
													three=0;
												}
												else if(dest==3)
												{
													four=0;
												}
												else if(dest==4)
												{
													five=0;
												}
												else if(dest==5)
												{
													six=0;
												}
												else if(dest==6)
												{
													seven=0;
												}

			}


}
break;
case 8:
{
	const char* cmp[8];
				    const char* answer_check[8];

				    std::string answer[8];
				    for(int b=0;b<query[index1].ans.length();b++)
				    {
				    	answer[b]=query[index1].ans[b];
				    }
				    for(int g=0;g<8;g++)
				    {
				    	answer_check[g]=answer[g].c_str();
				    }
	float xpoints[8]={86,170,254,338,430,514,598,672};
	if(xposition!=86&&xposition!=170&&xposition!=254&&xposition!=338&&xposition!=430&&xposition!=514&&xposition!=598&&xposition!=672)
	{
	if(one==0)
	{
	count=0;
	x[count]=sender->getPosition().x;
	y[count]=sender->getPosition().y;one=1;lastval=7;
	sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[0],432)));
	sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[0],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));
	//sender->runAction(CCMoveTo::create(0.05,ccp(xpoints[0],432)));
	fprintf(stderr,"\nx:---%f,,y=---%f",x[count],y[count]);
	const char *a=sprite->getString();
	cmp[0]=a;
	xcount[0]=stricmp(cmp[0],answer_check[0]);

	}
	else if(two==0)
	{
	count=1;
	x[count]=sender->getPosition().x;
	y[count]=sender->getPosition().y;two=1;lastval=7;
	sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[1],432)));
	sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[1],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));
	//sender->runAction(CCMoveTo::create(0.05,ccp(xpoints[1],432)));

	const char *a=sprite->getString();
	cmp[1]=a;
	xcount[1]=stricmp(cmp[1],answer_check[1]);
	}
	else if(three==0)
	{
	count=2;
	x[count]=sender->getPosition().x;
	y[count]=sender->getPosition().y;three=1;lastval=7;
	sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[2],432)));
	sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[2],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));
	//sender->runAction(CCMoveTo::create(0.05,ccp(xpoints[2],432)));
	const char *a=sprite->getString();
	cmp[2]=a;
	xcount[2]=stricmp(cmp[2],answer_check[2]);

	}
	else if(four==0)
	{
	count=3;
	x[count]=sender->getPosition().x;
	y[count]=sender->getPosition().y;four=1;lastval=7;
	sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[3],432)));
	sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[3],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));
	//sender->runAction(CCMoveTo::create(0.05,ccp(xpoints[3],432)));
	const char *a=sprite->getString();
	cmp[3]=a;
	xcount[3]=stricmp(cmp[3],answer_check[3]);

	}
	else if(five==0)
	{
	count=4;
	x[count]=sender->getPosition().x;
	y[count]=sender->getPosition().y;five=1;lastval=7;
	sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[4],432)));
	sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[4],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));
	//sender->runAction(CCMoveTo::create(0.05,ccp(xpoints[4],432)));
	const char *a=sprite->getString();
	cmp[4]=a;
	xcount[4]=stricmp(cmp[4],answer_check[4]);

	}
	else if(six==0)
	{
	count=5;
	x[count]=sender->getPosition().x;
	y[count]=sender->getPosition().y;six=1;lastval=7;
	sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[5],432)));
	sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[5],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));
	//sender->runAction(CCMoveTo::create(0.05,ccp(xpoints[5],432)));
	const char *a=sprite->getString();
	cmp[5]=a;
	xcount[5]=stricmp(cmp[5],answer_check[5]);

	}
	else if(seven==0)
	{
	count=6;
	x[count]=sender->getPosition().x;
	y[count]=sender->getPosition().y;seven=1;lastval=7;
	sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[6],432)));
	sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[6],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));
	//sender->runAction(CCMoveTo::create(0.05,ccp(xpoints[6],432)));
	const char *a=sprite->getString();
	cmp[6]=a;
	xcount[5]=stricmp(cmp[6],answer_check[6]);

	}
	else if(eight==0)
	{
	count=7;
	x[count]=sender->getPosition().x;
	y[count]=sender->getPosition().y;eight=1;
	const char *a=sprite->getString();
	cmp[7]=a;
	xcount[7]=stricmp(cmp[7],answer_check[7]);

	lastval=7;
	sprite->runAction(CCMoveTo::create(0.05,ccp(xpoints[7],432)));
	sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(xpoints[7],432)),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::tick)),NULL));
	lastimg=dynamic_cast<CCMenuItemImage *> (sender);
	lastletter=dynamic_cast<CCLabelTTF *> (sprite);
	//this->schedule(schedule_selector(HelloWorld::tick));
	}
	}
	else
	{
	int dest;
	float rmposition=sender->getPosition().x;
	for(int i=0;i<8;i++)
	{
	if(rmposition==xpoints[i])
	{
	dest=i;
	}
	}
	fprintf(stderr,"x:%f  y:%f",x[dest],y[dest]);
	sprite->runAction(CCMoveTo::create(0.05,ccp(x[dest],y[dest])));
	//sender->runAction(CCMoveTo::create(0.05,ccp(x[dest],y[dest])));
	sender->runAction(CCSequence::create(CCMoveTo::create(0.05,ccp(x[dest],y[dest])),CCCallFuncN::create(this,callfuncN_selector(HelloWorld::ulev)),NULL));
	if(dest==0)
	{
	one=0;
	}
	else if(dest==1)
	{
	two=0;
	}
	else if(dest==2)
	{
	three=0;
	}
	else if(dest==3)
	{
	four=0;
	}
	else if(dest==4)
	{
	five=0;
	}
	else if(dest==5)
	{
	six=0;
	}
	else if(dest==6)
	{
	seven=0;
	}
	else if(dest==7)
	{
	eight=0;
	}

	}

}
break;

		}	//switch end
	}
		}

	void HelloWorld::createv(int id,int len)
	{
		for(int i=0;i<len;i++)
					query[id].quer[i]=query[id].ans[i];
					for(int j=len,i=0;j<12;j++,i++)
						query[id].quer[j]=query[id].other[i];
	}
void HelloWorld::levelpc1()
{

	query[0].ans="korea";
			query[0].other="teashgs";

			HelloWorld::createv(0,5);
			query[1].ans="japan";
			query[1].other="hkogbxy";
			HelloWorld::createv(1,5);

			query[2].ans="bar";
					query[2].other="rkxynmeio";
					HelloWorld::createv(2,3);
					query[3].ans="friends";
			query[3].other="ougxw";
			HelloWorld::createv(3,query[3].ans.length());
			query[4].ans="jat";
					query[4].other="rmxypmeio";
					HelloWorld::createv(4,query[4].ans.length());
					query[5].ans="casper";
			query[5].other="nmeiob";
			HelloWorld::createv(5,query[5].ans.length());
			query[6].ans="garfield";
			query[6].other="qyxm";
			HelloWorld::createv(6,query[6].ans.length());
			query[7].ans="goofy";
						query[7].other="tiougbaw";
						HelloWorld::createv(7,query[7].ans.length());
						query[8].ans="archery";
						query[8].other="iuobg";
						HelloWorld::createv(8,query[8].ans.length());
						query[9].ans="biathlon";
								query[9].other="emcq";
								HelloWorld::createv(9,query[9].ans.length());
								query[10].ans="bocce";
						query[10].other="maighnqy";
						HelloWorld::createv(10,query[10].ans.length());
						query[11].ans="boxing";
								query[11].other="eyjypq";
								HelloWorld::createv(11,query[11].ans.length());
								query[12].ans="luge";
						query[12].other="yauoibgx";
						HelloWorld::createv(12,query[12].ans.length());
						query[13].ans="snooker";
						query[13].other="qprgs";
						HelloWorld::createv(13,query[13].ans.length());
						query[14].ans="elvis";
									query[14].other="grbqyop";
									HelloWorld::createv(14,query[14].ans.length());
									query[15].ans="pele";
									query[15].other="yqborolb";
									HelloWorld::createv(15,query[15].ans.length());
									query[16].ans="beyonce";
											query[16].other="ncqyh";
											HelloWorld::createv(16,query[16].ans.length());
											query[17].ans="diva";
									query[17].other="qyeuicvw";
									HelloWorld::createv(17,query[17].ans.length());
									query[18].ans="glamour";
											query[18].other="opgmbqx";
											HelloWorld::createv(18,query[18].ans.length());
											query[19].ans="fashion";
									query[19].other="ghyxo";
									HelloWorld::createv(19,query[19].ans.length());
									query[20].ans="footwear";
									query[20].other="uiyx";
									HelloWorld::createv(20,query[20].ans.length());
												query[21].ans="theater";
												query[21].other="bvdfq";
												HelloWorld::createv(21,query[21].ans.length());
												query[22].ans="back";
														query[22].other="sdfpoiqy";
														HelloWorld::createv(22,query[22].ans.length());
														query[23].ans="diaper";
												query[23].other="urbpln";
												HelloWorld::createv(23,query[23].ans.length());
												query[24].ans="barbie";
														query[24].other="qyxmqp";
														HelloWorld::createv(24,query[24].ans.length());


														query[25].ans="nirvana";
																query[25].other="quyxm";

																HelloWorld::createv(25,query[25].ans.length());
																query[26].ans="popeye";
																query[26].other="mloyaw";
																HelloWorld::createv(26,query[26].ans.length());

																query[27].ans="easter";
																		query[27].other="ghtrvf";
																		HelloWorld::createv(27,query[27].ans.length());
																		query[28].ans="marriage";
																query[28].other="lpqw";
																HelloWorld::createv(28,query[28].ans.length());
																query[29].ans="sex";
																		query[29].other="brqypefls";
																		HelloWorld::createv(29,query[29].ans.length());
																		query[30].ans="twitter";
																query[30].other="cuiod";
																HelloWorld::createv(30,query[30].ans.length());
																query[31].ans="batman";
																query[31].other="qymdbs";
																HelloWorld::createv(31,query[31].ans.length());
																query[32].ans="egypt";
																			query[32].other="ghtrvuf";
																			HelloWorld::createv(32,query[32].ans.length());
																			query[33].ans="rome";
																			query[33].other="asdflkgu";
																			HelloWorld::createv(33,query[33].ans.length());
																			query[34].ans="beer";
																					query[34].other="oiuyxapn";
																					HelloWorld::createv(34,query[34].ans.length());
																					query[35].ans="chicago";
																			query[35].other="ghtpx";
																			HelloWorld::createv(35,query[35].ans.length());
																			query[36].ans="rihanna";
																					query[36].other="ypvbq";
																					HelloWorld::createv(36,query[36].ans.length());
																					query[37].ans="lady";
																			query[37].other="bnyoqpmc";
																			HelloWorld::createv(37,query[37].ans.length());
																			query[38].ans="titanic";
																			query[38].other="qpaye";
																			HelloWorld::createv(38,query[38].ans.length());
																			query[39].ans="italy";
																						query[39].other="uievcpq";
																						HelloWorld::createv(39,query[39].ans.length());
																						query[40].ans="facebook";
																						query[40].other="uievcpq";
																						HelloWorld::createv(40,query[40].ans.length());
																						query[41].ans="sox";
																								query[41].other="cyapltgh";
																								HelloWorld::createv(41,query[41].ans.length());
																								query[42].ans="darts";
																						query[42].other="puiohgj";
																						HelloWorld::createv(42,query[42].ans.length());
																						query[43].ans="michael";
																								query[43].other="ghqpy";
																								HelloWorld::createv(43,query[43].ans.length());
																								query[44].ans="superman";
																						query[44].other="btzc";
																						HelloWorld::createv(44,query[44].ans.length());
																						query[45].ans="banana";
																						query[45].other="bobqwa";
																						HelloWorld::createv(45,query[45].ans.length());
																									query[46].ans="tennis";
																									query[46].other="dfglyx";
																									HelloWorld::createv(46,query[46].ans.length());
																									query[47].ans="math";
																											query[47].other="eqwpalsj";
																											HelloWorld::createv(47,query[47].ans.length());
																											query[48].ans="pizza";
																									query[48].other="bmdxevm";
																									HelloWorld::createv(48,query[48].ans.length());
																									query[49].ans="chess";
																											query[49].other="poqwyml";
																											HelloWorld::createv(49,query[49].ans.length());
						query[50].ans="break";
						query[50].other="uievcpq";
						HelloWorld::createv(50,query[50].ans.length());
						query[51].ans="white";
						query[51].other="rtcxsap";
						HelloWorld::createv(51,query[51].ans.length());
						query[52].ans="cowboy";
						query[52].other="ghjddl";
						HelloWorld::createv(52,query[52].ans.length());
						query[53].ans="blue";
						query[53].other="trzaxoqy";
						HelloWorld::createv(53,query[53].ans.length());
						query[54].ans="canoeing";
						query[54].other="bvod";
						HelloWorld::createv(54,query[54].ans.length());
						query[55].ans="salt";
						query[55].other="qwepyxls";
						HelloWorld::createv(55,query[55].ans.length());
						query[56].ans="water";
						query[56].other="plokjin";
						HelloWorld::createv(56,query[56].ans.length());
						query[57].ans="weather";
						query[57].other="ghjbn";
						HelloWorld::createv(57,query[57].ans.length());
						query[58].ans="beach";
						query[58].other="kolpqae";
						HelloWorld::createv(58,query[58].ans.length());
						query[59].ans="ireland";
						query[59].other="cvqfg";
						HelloWorld::createv(59,query[59].ans.length());
						query[60].ans="mercedes";
						query[60].other="yqui";
						HelloWorld::createv(60,query[60].ans.length());
						query[61].ans="sweet";
						query[61].other="ghqpoeq";
						HelloWorld::createv(61,query[61].ans.length());
						query[62].ans="sword";
						query[62].other="ghjtzvc";
						HelloWorld::createv(62,query[62].ans.length());
						query[63].ans="fitness";
						query[63].other="yxcqp";
						HelloWorld::createv(63,query[63].ans.length());
						query[64].ans="ferrari";
						query[64].other="mnmyxq";
						HelloWorld::createv(64,query[64].ans.length());
						query[65].ans="kimono";
						query[65].other="srydxw";
						HelloWorld::createv(65,query[65].ans.length());
						query[66].ans="clock";
						query[66].other="ghrnuiy";
						HelloWorld::createv(66,query[66].ans.length());
						query[67].ans="dolphin";
						query[67].other="ghjdx";
						HelloWorld::createv(67,query[67].ans.length());
						query[68].ans="snickers";
						query[68].other="youi";
						HelloWorld::createv(68,query[68].ans.length());
						query[69].ans="tesla";
						query[69].other="bchvryp";
						HelloWorld::createv(69,query[69].ans.length());
						query[70].ans="aladdin";
						query[70].other="brgui";
						HelloWorld::createv(70,query[70].ans.length());
						query[71].ans="scotland";
						query[71].other="uiby";
						HelloWorld::createv(71,query[71].ans.length());
						query[72].ans="shopping";
						query[72].other="xscy";
						HelloWorld::createv(72,query[72].ans.length());
						query[73].ans="tourist";
						query[73].other="nkmjv";
						HelloWorld::createv(73,query[73].ans.length());
						query[74].ans="flower";
						query[74].other="ncmfgx";
						HelloWorld::createv(74,query[74].ans.length());
}
void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
void HelloWorld::buycoins()
{
	if(unlocking==0)
	{
		unlocking=1;
	if(this->getChildByTag(102))
	{
		for(int i=1;i<=10;i++)
			this->removeChildByTag(102,true);
	}
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	CCSprite* pSprite = CCSprite::create("bg_tips@2x.png");
	pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	this->addChild(pSprite,799);
	pSprite->setTag(101);
	CCLabelTTF* helpers=CCLabelTTF::create("Buy Coins","Arial",60);
	helpers->setPosition(ccp(385,960));
	helpers->setColor(ccc3(72,61,135));
	this->addChild(helpers,800);
	helpers->setTag(101);
	CCMenuItemImage *pSpritereveal = CCMenuItemImage::create("btn_buy_coins@2x.png","btn_buy_coins@2x.png",this,menu_selector(HelloWorld::conf));
	pSpritereveal->setPosition(ccp(385,830));
	pSpritereveal->setTag(178);
	this->addChild(pSpritereveal,800);
	//pSpritereveal->setTag(101);
	CCLabelTTF* reveal=CCLabelTTF::create("750 Coins           1.99","Arial",35);
	reveal->setPosition(ccp(pSpritereveal->getPosition().x-10,pSpritereveal->getPosition().y));
	this->addChild(reveal,801);
	reveal->setTag(101);
	CCSprite *rupe=CCSprite::create("rupee.png");
	rupe->setPosition(ccp(reveal->getPosition().x+90,reveal->getPosition().y));
	this->addChild(rupe,801);
	rupe->setTag(101);
	CCMenuItemImage *pSpriteremove = CCMenuItemImage::create("btn_buy_coins@2x.png","btn_buy_coins@2x.png",this,menu_selector(HelloWorld::conf));
	pSpriteremove->setPosition(ccp(pSpritereveal->getPosition().x,pSpritereveal->getPosition().y-130));
	pSpriteremove->setTag(188);
	this->addChild(pSpriteremove,800);
	//pSpriteremove->setTag(101);
	CCLabelTTF* removal=CCLabelTTF::create("2000 Coins         3.99","Arial",35);
	removal->setPosition(ccp(pSpriteremove->getPosition().x-10,pSpriteremove->getPosition().y));
	this->addChild(removal,801);
	removal->setTag(101);
	CCSprite *rupe1=CCSprite::create("rupee.png");
	rupe1->setPosition(ccp(removal->getPosition().x+90,removal->getPosition().y));
	this->addChild(rupe1,801);
	rupe1->setTag(101);
	CCMenuItemImage *pSprite3 = CCMenuItemImage::create("btn_buy_coins@2x.png","btn_buy_coins@2x.png",this,menu_selector(HelloWorld::conf));
	pSprite3->setTag(198);
	pSprite3->setPosition(ccp(pSpriteremove->getPosition().x,pSpriteremove->getPosition().y-130));
	this->addChild(pSprite3,800);
	//pSprite3->setTag(101);
	CCLabelTTF* buycoins=CCLabelTTF::create("4000 Coins         6.99","Arial",35);
	buycoins->setPosition(ccp(pSprite3->getPosition().x-10,pSprite3->getPosition().y));
	this->addChild(buycoins,801);
	buycoins->setTag(101);
	CCSprite *rupe2=CCSprite::create("rupee.png");
	rupe2->setPosition(ccp(buycoins->getPosition().x+90,buycoins->getPosition().y));
	this->addChild(rupe2,801);
	rupe2->setTag(101);
	CCMenuItemImage *pSprite4 = CCMenuItemImage::create("btn_buy_coins@2x.png","btn_buy_coins@2x.png",this,menu_selector(HelloWorld::conf));
	pSprite4->setTag(208);
	pSprite4->setPosition(ccp(pSprite3->getPosition().x,pSprite3->getPosition().y-130));
	this->addChild(pSprite4,800);
	//pSprite4->setTag(101);
	CCLabelTTF* buycoins1=CCLabelTTF::create("10000 Coins        9.99","Arial",35);
	buycoins1->setPosition(ccp(pSprite4->getPosition().x-10,pSprite4->getPosition().y));
	this->addChild(buycoins1,801);
	buycoins1->setTag(101);
	CCSprite *rupe3=CCSprite::create("rupee.png");
	rupe3->setPosition(ccp(buycoins1->getPosition().x+90,buycoins1->getPosition().y));
	this->addChild(rupe3,801);
	rupe3->setTag(101);
	CCMenuItemImage *pSpriteclose = CCMenuItemImage::create("btn_close@2x.png","btn_close@2x.png",this,menu_selector(HelloWorld::close1));
	pSpriteclose->setPosition(ccp(pSprite4->getPosition().x,pSprite4->getPosition().y-100));
	CCLabelTTF* close=CCLabelTTF::create("Close","Arial",35);
	close->setPosition(ccp(pSpriteclose->getPosition().x-5,pSpriteclose->getPosition().y));
	close->setTag(101);
	this->addChild(close,802);
	CCMenu* pMenu1 = CCMenu::create(pSpriteclose,pSpritereveal,pSpriteremove,pSprite3,pSprite4, NULL);
	pMenu1->setPosition(CCPointZero);
	this->addChild(pMenu1, 800);
	pMenu1->setTag(101);
	}
}
void HelloWorld::conf(CCNode *sender)
{
	CCLabelTTF *labelbuy=CCLabelTTF::create("","Arial",35.0);
			labelbuy->setPosition(ccp(395,700));
			this->addChild(labelbuy,500001);
			labelbuy->setTag(3578);
	int tg=sender->getTag();
		if(tg==178)
		{
			fprintf(stderr,"tag 178");
			digital_good_id= "26382874";
			digital_good_name= "750 coins";
			digital_good_sku= "pack2";
			metadata= "Small Coin Pack to help you start solving puzzles";
			labelbuy->setString("Do you want to buy 750 coins\n with $1.99");

		}
		else if(tg==188)
		{
			digital_good_id="26382875";
			digital_good_name= "2.000 Coins";
					digital_good_sku= "pack3";
					metadata= "Coin Pack to help you start solving puzzles";
					labelbuy->setString("Do you want to buy 1500 coins\n with 3.99");
		}
		else if(tg==198)
				{
					digital_good_id="26382876";
					digital_good_name= "4.000 Coins";
							digital_good_sku= "pack4";
							metadata= "Best Buy Coin Pack";
							labelbuy->setString("Do you want to buy 5250 coins\n with $6.99");
				}
		else if(tg==208)
					{
						digital_good_id="26382877";
						digital_good_name= "10.000 Coins";
								digital_good_sku= "pack5";
								metadata= "Huge Pack of Coins";
								labelbuy->setString("Do you want to buy 12000 coins\n with $9.99");
					}
	CCSprite *bg=CCSprite::create("back12.png");
	bg->setPosition(ccp(size.width/2,size.height/2));
	bg->setTag(3578);
	this->addChild(bg,500000);
	CCMenuItemImage *cancle=CCMenuItemImage::create("b1b.png","b2b.png",this,menu_selector(HelloWorld::closesbuy));
	cancle->setPosition(ccp(240,520));
	CCMenuItemImage *buy=CCMenuItemImage::create("bb1b.png","bb2b.png",this,menu_selector(HelloWorld::buycommit));
	buy->setPosition(ccp(540,520));
		CCMenu *buymenu=CCMenu::create(buy,cancle,NULL);
		buymenu->setPosition(CCPointZero);
		this->addChild(buymenu,500001);
		buymenu->setTag(3578);


}
void HelloWorld::buycommit()
{
	fprintf(stderr,"hai babi");

unsigned request_id = 0;

		    // Changed CCEGLView to create a window group with ID of getPID
		    char windowGroupID[16];
		    snprintf(windowGroupID, sizeof(windowGroupID), "%d", getpid());

			if (paymentservice_purchase_request(digital_good_id, digital_good_sku,
			    digital_good_name, metadata, purchase_app_name, purchase_app_icon,
			    windowGroupID, &request_id) != BPS_SUCCESS)
			{
				fprintf(stderr, "Error: purchase request failed.\n");
			}


			bps_event_t *event = NULL;

			while(true)
			{

				bps_get_event(&event, 1);

				if (event) {
					if (bps_event_get_domain(event) == paymentservice_get_domain())
					{
						if (SUCCESS_RESPONSE == paymentservice_event_get_response_code(event))
						{
							if (PURCHASE_RESPONSE == bps_event_get_code(event))
							{
								// Handle a successful purchase here
								const char* digital_good = paymentservice_event_get_digital_good_id(event, 0);
								const char* digital_sku = paymentservice_event_get_digital_good_sku(event, 0);

								onPurchaseSuccess(event); //comment this one if you don't want to put all info in console
								//int result = atoi(digital_good);

								return ;
							}
							else
							{
								// Handle a successful query for past purchases here
								int numPurchases = paymentservice_event_get_number_purchases(event);
								fprintf(stderr, "Handle a successful query for past purchases here");

								return;
							}
						}
						else
						{
							int error_id = paymentservice_event_get_error_id(event);
							const char* error_text = paymentservice_event_get_error_text(event);
							failureCommon(event); //comment this one if you don't want to put all info in console

							return;
						}
					}
				}
			}


}
void HelloWorld::closesbuy()
{
	for(int i=1;i<=3;i++)
	{
		this->removeChildByTag(3578);
	}
}
void HelloWorld::close1()
{
	unlocking=0;
	for(int i=1;i<=12;i++)
	this->removeChildByTag(101,true);
	this->removeChildByTag(178,true);
	this->removeChildByTag(188,true);
	this->removeChildByTag(198,true);
	this->removeChildByTag(208,true);

}
void HelloWorld::menuSelectCallback()
{

	HelloWorld::level1();
}




// bb payment servicess..............................///////////////////







void HelloWorld::get_window_group_id(const char *gpid)
{
//    static char s_window_group_id[16] = "";
//
//    if (s_window_group_id[0] == '\0') {
//        snprintf(s_window_group_id, sizeof(s_window_group_id), "%d", getpid());
//    }
//    fprintf(stderr,"\nhai");
//    fprintf(stderr,s_window_group_id);
//    return s_window_group_id;
	fprintf(stderr,"%s",gpid);
	groupid=gpid;
	fprintf(stderr,"%s",groupid);
}

/**
 * Set up a basic screen, so that the navigator will
 * send window state events when the window state changes.
 *
 * @return @c EXIT_SUCCESS or @c EXIT_FAILURE
 */


/**
 * Handle the failure case for either event. Print the error information.
 */
void HelloWorld::failureCommon(bps_event_t *event)
{
	fprintf(stderr,"\nentered in to failure");
    if (event == NULL) {
        fprintf(stderr, "Invalid event.\n");
        return;
    }

    unsigned request_id = paymentservice_event_get_request_id(event);
    int error_id = paymentservice_event_get_error_id(event);
    const char* error_text = paymentservice_event_get_error_text(event);

    fprintf(stderr, "Payment System error. Request ID: %d  Error ID: %d  Text: %s\n",
            request_id, error_id, error_text ? error_text : "N/A");
    //this->unschedule(schedule_selector(HelloWorld::sched));
    HelloWorld::closesbuy();
}

/**
 * Upon successful completion of a purchase, print a string containing
 * information about the digital good that was purchased.
 */
void HelloWorld::onPurchaseSuccess(bps_event_t *event)
{
    if (event == NULL) {
        fprintf(stderr, "Invalid event.\n");
        return;
    }

    unsigned request_id = paymentservice_event_get_request_id(event);
    const char* date = paymentservice_event_get_date(event, 0);
    const char* digital_good = paymentservice_event_get_digital_good_id(event, 0);
    const char* digital_sku = paymentservice_event_get_digital_good_sku(event, 0);
    const char* license_key = paymentservice_event_get_license_key(event, 0);
    const char* metadata = paymentservice_event_get_metadata(event, 0);
    const char* purchase_id = paymentservice_event_get_purchase_id(event, 0);

    fprintf(stderr, "Purchase success. Request Id: %d\n Date: %s\n DigitalGoodID: %s\n SKU: %s\n License: %s\n Metadata: %s\n PurchaseId: %s\n\n",
        request_id,
        date ? date : "N/A",
        digital_good ? digital_good : "N/A",
        digital_sku ? digital_sku : "N/A",
        license_key ? license_key : "N/A",
        metadata ? metadata : "N/A",
        purchase_id ? purchase_id : "N/A");
    //this->unschedule(schedule_selector(HelloWorld::sched));
    HelloWorld::closesbuy();

}

/**
 * On successful completion of a get existing purchases request,
 * print the existing purchases.
 */
void HelloWorld::onGetExistingPurchasesSuccess(bps_event_t *event)
{
    if (event == NULL) {
        fprintf(stderr, "Invalid event.\n");
        return;
    }

    unsigned request_id = paymentservice_event_get_request_id(event);
    int purchases = paymentservice_event_get_number_purchases(event);

    fprintf(stderr, "Get existing purchases success. Request ID: %d\n", request_id);
    fprintf(stderr, "Number of existing purchases: %d\n", purchases);
    fprintf(stderr, "Existing purchases:\n");

    int i = 0;
    for (i = 0; i<purchases; i++) {
        const char* date = paymentservice_event_get_date(event, i);
        const char* digital_good = paymentservice_event_get_digital_good_id(event, i);
        const char* digital_sku = paymentservice_event_get_digital_good_sku(event, i);
        const char* license_key = paymentservice_event_get_license_key(event, i);
        const char* metadata = paymentservice_event_get_metadata(event, i);
        const char* purchase_id = paymentservice_event_get_purchase_id(event, i);

        fprintf(stderr, "  Date: %s  PurchaseID: %s  DigitalGoodID: %s  SKU: %s  License: %s  Metadata: %s\n",
            date ? date : "N/A",
            purchase_id ? purchase_id : "N/A",
            digital_good ? digital_good : "N/A",
            digital_sku ? digital_sku : "N/A",
            license_key ? license_key : "N/A",
            metadata ? metadata : "N/A");
    }
    //this->unschedule(schedule_selector(HelloWorld::sched));
}


