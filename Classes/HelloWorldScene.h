#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#ifndef NDEBUG
#include <assert.h>
#define ASSERT(a) (assert(a))
#else
#define ASSERT(a)
#endif

class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
        // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();

    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    void addbackground();
       void mainscene();

       void sched();
       void onGetExistingPurchasesSuccess(bps_event_t *event);
       void onPurchaseSuccess(bps_event_t *event);
       void level1pack();
       void level2pack();
       void level3pack();
     //  int setup_screen();
       void tick();
       void blink();
       void menuSelectCallback();
       void mutesound();
       void moveback(CCNode *lastimg,CCNode *lastletter);
       void scalee(CCNode *sender);
       void updt();
void deff(CCNode *sender);

    void level1();
    void secletletter(CCNode *sender);
    void ulev();
       void buycoins();
       void failureCommon(bps_event_t *event);
        void get_window_group_id(const char*gpid);
        void revealletter();
        void removeletter();
    void helper();
    void close1();
    void close2();
    void closesbuy();
    void buycommit();
    void conf(CCNode *sender);
    void levelpc1();
    void createv(int id,int len);

    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
