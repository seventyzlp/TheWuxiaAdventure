//
//  main.cpp
//  TheWuxiaAdventure
//
//  Created by  张乐平 on 2021/11/11.
//

#include <iostream>
#include <unistd.h>//睡眠
#include <cstdlib> //随机数
#include <ctime>//为了重构随机数加的读取系统时间函数
//#include "conio.h" //操这个库win独占妈的
#include <iomanip>
using namespace std;
string name;
float old;//解决了一开始可以无限打坐不花时间
int level,Money;//有升级检测优化代码
int experience,JustisePoint,WuPoint;
string MenPai;
void myself();
void Practise();
void Lilian();
void shifu();
void Upgrate();
void Attack();//战斗
void Xianguang();
void EnemySpawn();//生成敌人
void Shop();//商店内容
void Buy();
float MyStrong;
float EnemyStrong;
bool BaiShiorNot,ShimenShaoling;
bool BaishiHint,ChenjianHint,XianguangHint;
char x;
int main(int argc, const char * argv[]) {
   // getchar();//暂停代码执行，按回车继续执行
    MenPai="无门无派";
    ShimenShaoling=true;
    srand((int)time(0));//重置随机数种子
    WuPoint=rand()%10+1;//随机生成悟性等级
    cout<<"著作权所有 copyright〈2021〉〈张乐平〉"<<endl;
    cout <<"江湖风云"<< "   侠之大者";
    cout <<"你是江湖上的一个无名小卒"<< endl;
    cout<<"南朝四百八十寺，多少楼台烟雨中"<<endl;
    cout <<"为了能够制霸武林，平定中原，你决定用一生的时间来修炼"<<endl;
    //sleep(1);//数字是多少就是几秒
    cout<<"你出生了"<<endl;
    myself();
    cout<< "                            初入武林"<<endl;
    cout<<"你无依无靠，只能按照一本武功残典，暗自琢磨功法"<<endl;
    cout<<"按P进行打坐，尝试运转体内功法"<<endl;
    cout<<"按m查看自己的属性"<<endl;
    cout<<"“提示：所有的输入都需要按回车确定，只能接受单字符输入，有些时候文本会有暂停来体现时间流逝，请参考前后文并且耐心等待，别急着输入“\n";
    while (true) {//整个游戏的大循环
        MyStrong=experience*level*0.1-old+10;//随便设定一个力量值
        if (old>=100) {
            EnemySpawn();
            EnemyStrong+=experience*0.1*WuPoint;
            cout<<"你的寿元已尽"<<endl;
            sleep(1);
            cout<<"天劫落下，你知道只有熬过天劫才能修炼成仙\n";
            cout<<"你运转全身功体，把精神集中到最巅峰的时刻，准备迎接这一道道天劫\n";
            if (MyStrong>=EnemyStrong) {
                cout<<"道道天劫在你身上似乎并没有留下什么伤痕\n";
                cout<<"你熬过了天劫，你感到自己全身逐渐轻盈\n";
                cout<<"你飞升到了天界，你以成仙\n";
                cout<<" ————————————————————————————游戏结束————————————————————";
                myself();
                break;
            }
            else{
                cout<<"天劫把你劈成了碎片"<<endl;
                cout<<"你死了"<<endl;
                cout<<" ————————————————————————————游戏结束————————————————————";
                myself();
                break;
            }
        }//去世
        if (!BaishiHint and level>=10){
            BaishiHint=true;
            cout<<"你可以加入门派了！按s进入门派界面！"<<endl;
        }//触发拜师
        if (!ChenjianHint and level>=5){
            ChenjianHint=true;
            cout<<"如今的江湖已经越发混沌，逐渐成长的你打算出门历练，按L进行历练"<<endl;
        }//触发历练
        if (level>=3 and !XianguangHint) {
            XianguangHint=true;
            cout<<"你向来是个闲不住的人，呆在家里打坐完全没法满足你对外面世界的好奇心，你可以按x出去闲逛了！"<<endl;
        }//触发闲逛
        cin>>x;
        switch (x) {
            case 'p':
                Practise();//打坐
                break;
            case 's':
                shifu();//拜师
                break;
            case 'l':
                Lilian();//历练
                break;
            case 'm':
                myself();//看自己属性
                break;
            case 'x':
                Xianguang();//闲逛
                break;
            case 'b':
                Shop();//买东西
                break;
            default:
                cout<<"输入错误，请重新输入"<<endl;
                break;
        }//主循环，采用了switch语句，流畅的不行
    }
    return 0;
}
void myself(){
    cout<<"你现在"<<old<<"岁\n";
    cout<<"你现在"<<level<<"级\n";
    cout<<"你是"<<MenPai<<endl;
    cout<<"你现在有"<<experience<<"的经验\n";//这里做一个可以显示下一级还有多少经验的操作
    cout<<"你的悟性是"<<WuPoint<<endl;
    cout<<"你现在有"<<JustisePoint<<"正义\n";
    cout<<"你的战斗力是"<<MyStrong<<endl;
    cout<<"你有"<<Money<<"钱\n";
};
void Practise(){
    experience=experience+1*WuPoint;//这里的数字需要给个条件，数学计算之后在说吧
    old=old+0.1;//每一次修炼就会变老
    cout<<"你花费了0.1年的时间在家打坐吐纳，增加了1点经验值"<<endl;
    cout<<"你现在有"<<experience<<"点经验值"<<endl;
    Upgrate();
};
void shifu(){
    if (!BaiShiorNot and JustisePoint>=10 and ShimenShaoling){
        cout<<"路过的少林派大弟子见到了你，想要收你加入,按Y同意，按其他键拒绝"<<endl;
        cin>>x;
        if (x=='y') {
            BaiShiorNot=true;//已经拜师
            MenPai="少林派";
            cout<<"终于加入师门了！你的师父让你按S进行修炼"<<endl;
        }
        else{
            ShimenShaoling=false;//防止每次都是少林
        }
    }
    else if (!BaiShiorNot and JustisePoint>=20){
        cout<<"在一次历练中，你偶然解救了武当派的长老，为了报答你的救命之恩，决定吸纳你加入武当派"<<endl;
        cout<<"按Y同意，按其他键拒绝"<<endl;
        cin>>x;
        if (x=='y') {
            BaiShiorNot=true;//已经拜师
            MenPai="武当派";
            cout<<"终于加入师门了！你的师父让你按S进行修炼"<<endl;
        }
    }
    else if (!BaiShiorNot){
        cout<<"你已经从江湖上知晓了武当与少林两大门派，要是能加入该有多好，还是多去历练历练吧"<<endl;
    }
    if (MenPai=="武当派"){//比较叼一点
        cout<<"作为一位武当弟子，你来到了武当习武堂，打算学习武当的功法"<<endl;
        old=old+5;
        experience=experience+40*WuPoint;
        JustisePoint=JustisePoint+3;
        cout<<"师父似乎并没有让你闲下来的意思，在历练的5年中，你一点闲下来的时间都没有"<<endl;
        cout<<"你现在有"<<experience<<"点经验值"<<endl;
        Upgrate();
    }
    else if (MenPai=="少林派"){//比较拉一点的门派
        cout<<"作为一位少林弟子，你来到了少林习武堂，打算学习少林的功法"<<endl;
        old=old+3;
        experience=experience+20*WuPoint;
        JustisePoint=JustisePoint+1;
        cout<<"少林人员稀少，在熙熙攘攘的人群之中，3年时光眨眼过去，可以说是收获颇丰了"<<endl;
        cout<<"你现在有"<<experience<<"点经验值"<<endl;
        Upgrate();

    }
};
void Lilian() {
    experience=experience+5*WuPoint;
    old=old+1;
    JustisePoint++;
    cout<<"你出门历练1年，惩戒了几个匪徒，获得了5点经验，因为帮助人们解决问题，你感到自己更加正义了（正义值+1）"<<endl;
    cout<<"你现在有"<<experience<<"点经验值"<<endl;
    Money+=20;
    cout<<"当地的官员奖励你了20钱，非常开心\n";
    Upgrate();
};
void Upgrate(){
    if (experience >= level*level ) {
        level++;
        cout<<"历经千幸万苦，你终于升级了,来到了"<<level<<"级"<<endl;//升级成功给个提示
    }
};//检测有没有升级
void Xianguang(){
    old=old+1;
    cout<<"你在外面独自闲逛"<<endl;
    sleep(1);
    cout<<"你在江南寻花问柳，吟诗作对"<<endl;
    srand((int)time(0));
    if (rand() % 2==1) {
        cout<<"突然，你注意到魔教帮派天龙教的人在村口为非作歹，按Y上前帮忙"<<endl;
        cin>>x;
        if (x=='y') {
            cout<<"你借助凌厉的脚步，挤入人群，同那伙恶人打了起来"<<endl;
            JustisePoint++;
            EnemySpawn();
            Attack();
        }
        else{
            cout<<"你觉得自己还是不要惹事生非为好，侧身一遁，你混入了人群，悄悄离开"<<endl;
            sleep(2);
            cout<<"你的内心久久不能忘怀刚刚发生的事情，你如果出手，事情的结果说不定会改变（正义值降低）"<<endl;
            JustisePoint--;
        }
    }//恶霸路线
    else{
        cout<<"你来到了村口的古井前，谁也说不定下面没有好东西"<<endl;
        sleep(1);
        cout<<"你迟疑了一会，望着深不见底的水井"<<endl;
        cout<<"按Y跳下水井,按其他键离开"<<endl;
        cin>>x;
        if (x=='y') {
            cout<<"你纵身一跃，化为一条弧线投身进入了水井之中"<<endl;
            sleep(1);
            cout<<"井水很冷，刺痛了你的神经"<<endl;
            if (experience<=100) {
                cout<<"好冷好冷"<<endl;
                sleep(1);
                cout<<"你完全受不了井水的寒冷"<<endl;
                cout<<"还是赶紧上去吧"<<endl;
            }
            else if (experience>100 and experience<1000){
                cout<<"你运转内劲。似乎抵消掉了井水的寒冷"<<endl;
                sleep(1);
                cout<<"你持续下潜着"<<endl;
                sleep(1);
                cout<<"水越来越冷，你感觉到你运转功法的速度也慢了下来，似乎再也无法维持你的身体不受外界寒气的入侵"<<endl;
                cout<<"但是你感觉到了自己在下潜的过程中，内力得到了锻炼"<<endl;
                experience+=40*WuPoint;
                Upgrate();
                cout<<"但是继续潜下去可能会有危险，还是快点上去吧"<<endl;
            }
            else if (experience>=1000 and experience<=10000){
                cout<<"你有强烈的真气护体，似乎没有什么寒冷的东西能够阻挡你的脚步"<<endl;
                cout<<"你持续下潜"<<endl;
                sleep(2);
                cout<<"你持续下潜"<<endl;
                sleep(2);
                cout<<"你感觉水突然冷了下来，下面一定有什么极寒之物在散发寒冰之气"<<endl;
                cout<<"你每下潜一寸，便感受到寒气正在侵入你的一寸躯体，不知道应不应该冒险继续下潜"<<endl;
                cout<<"按y冒险下去，按其他键收手上浮\n";
                cin>>x;
                if (x=='y') {
                    cout<<"你决定冒险下沉，探索井水的真相"<<endl;
                    srand((int)time(0));
                    if (rand()%2==1) {
                        cout<<"虽然寒冷刺骨，但是灵气侵袭你躯体的速度远远不及你下潜的速度"<<endl;
                        sleep(1);
                        cout<<"你飞速下沉，你感到一阵寒冷,你的内力似乎已经完全不能抵御入侵的寒气"<<endl;
                        cout<<"你在忍受肉体被寒气入侵的痛苦"<<endl;
                        sleep(2);
                        cout<<"你很冷"<<endl;
                        sleep(2);
                        cout<<"你真的非常冷"<<endl;
                        sleep(2);
                        cout<<"终于，你好似突破了某些东西，一头跌进了井里的空洞"<<endl;
                        cout<<"你在洞窟内部仔细寻找..."<<endl;
                        sleep(5);
                        cout<<"你找到了万载玄冰髓，双手刚接触，你的内力便控制不住的运转，把全部的玄冰吸收进去"<<endl;
                        WuPoint+=20;
                        old+=5;
                        cout<<"你在洞窟内呼吸吐纳了5年之久，终于将这股强悍的力量囫囵吞食，是时候离开这里了"<<endl;
                    }//成功下泉，找到真相
                    else{
                        cout<<"虽然寒冷刺骨，但是灵气侵袭你躯体的速度远远不及你下潜的速度"<<endl;
                        sleep(1);
                        cout<<"你飞速下沉，你感到一阵寒冷,你的内力似乎已经完全不能抵御入侵的寒气"<<endl;
                        cout<<"你在忍受肉体被寒气入侵的痛苦"<<endl;
                        sleep(2);
                        cout<<"你很冷"<<endl;
                        sleep(2);
                        cout<<"你真的非常冷"<<endl;
                        cout<<"你感到体内的每一寸筋脉都被寒冷贯穿，在你体内流淌的真气已经完全停滞了下来\n";
                        sleep(2);
                        cout<<"你两眼一黑，晕了过去"<<endl;
                        experience-=200;
                        WuPoint-=3;
                        cout<<"你失去知觉，浮上水面，被人救起送回家中，你只好紧急运转功法，尽可能恢复曾经的元力，可惜，往往失去的东西都很难再找回来了\n";
                        cout<<"（悟性降低了3，经验降低了200点)\n";
                        old+=5;
                        cout<<"过了5年，你似乎痊愈了，于是你拖起疲惫的身体，再次步入江湖\n";
                    }//失败了，回去疗伤
                }
                else{
                    cout<<"你抽身而退，回到井口，你出水的身姿惊艳了路边路过的村民们"<<endl;
                    experience+=100*WuPoint;
                    Upgrate();
                    JustisePoint+=1;
                }
            }
            else if (experience>10000){
                cout<<"你借助自己体内运转的强大功法，轻松来到了古井的最深处"<<endl;
                cout<<"你仔细寻找"<<endl;
                sleep(2);
                cout<<"你发现了一团万载玄冰，可是在你看来，这玩意并不是什么你需要的东西\n";
                cout<<"你随手把这玩意扔在一边，继续搜寻着洞窟"<<endl;
                sleep(2);
                cout<<"终于，你在洞窟的角落取得了凌寒心法，当你看到这残破的封面之时，你就知道这正是你所需要的东西\n";
                cout<<"你不顾洞窟的艰险环境，打开秘籍，修炼了起来，就好像一个将要饿死的人扑到面包上那样，你全身心的投入到了修炼之中\n";
                old+=2;
                sleep(2);
                cout<<"不知不觉间，已经过去了2年之久\n";
                experience*=2;
                Upgrate();
            }
        }
    }//古井修炼路线
};//闲逛
void Attack(){
    cout<<"你二话不说，运转功法，朝着那人便打"<<endl;
    EnemySpawn();
    if (MyStrong>=EnemyStrong) {
        cout<<"全场的目光都集中在你们身上，你们两人则又凝神静气，彼此互相打量，你见他双眸炯炯，神光湛然，一看之下，竟似深得正宗内功精髓的一代宗师，要仔细观察，才瞧得出一两分邪气，心知他果然是参透了正邪两派的上乘武学，另辟练功蹊径，达到了正邪合一，扭转阴阳的境界，真是可怕"<<endl;
        sleep(1);
        cout<<"他“呼”的一声，一口气喷将出来，你只觉扑面冰寒，但这股寒流瞬即过去，接着便是春风拂面，好像一下子从肃杀的隆冬到了阳春三月，周围的空气也变得温和潮湿起来"<<endl;
        sleep(1);
        cout<<"殊不料你一掌既出，身子已抢到离他三四丈外，是一招“亢龙有悔”，后掌推前掌，双掌力道并在一起，排山倒海的压将过来"<<endl;
        sleep(2);
        cout<<"你还是留了一手，没有置人于死地，但是他也被你打的伤痕累累"<<endl;
        sleep(1);
        cout<<"“大侠！再也不敢了”随即那人便逃之夭夭"<<endl;
        cout<<"你收手而立，这才是大侠风范"<<endl;
        experience=experience+EnemyStrong*WuPoint;
        Upgrate();
        old=old+0.1;
        JustisePoint+=10;
    }//Win
    else{
        cout<<"只一瞬之间，你便觉气息窒滞，对方掌力竟如怒潮狂涌，势不可当，双如是一堵无形的高墙，向自己身前疾冲。你大惊之下，哪里还有余裕筹思对策，但知若是单掌出迎，势必臂断腕折，说不定全身筋骨尽碎，百忙中双掌连划三个半圆护住身前，同时足尖着力，飘身后退"<<endl;
        sleep(2);
        cout<<"在交战了一个回合之后，你便体力不支，难以为继之后的战斗"<<endl;
        cout<<"你内视丹元，却发现对方的内里早已入侵你的全身，若不快快屏息内疗，马上就会爆体而亡"<<endl;
        sleep(1);
        cout<<"你抽身而退，全然不顾围观者看待你怜悯的目光"<<endl;
        experience=experience+WuPoint;
        Upgrate();
        JustisePoint-=1;
        old=old+(EnemyStrong-MyStrong);
        cout<<"你在家疗伤"<<endl;
        sleep(2);
        cout<<"你在家疗伤"<<endl;
        sleep(2);
        cout<<"你在家疗伤"<<endl;
        sleep(2);
        cout<<"过了"<<EnemyStrong-MyStrong<<"年，你终于痊愈，再次踏上江湖之路"<<endl;
    }
};//战斗
void EnemySpawn(){
    srand((int)time(0));
    EnemyStrong=rand()%1000+old*20;//我也不晓得这个应该设置成多少
};//生成敌人
void Shop(){
    cout<<"你来到了商店"<<endl;
    cout<<"你有"<<Money<<"钱"<<endl;
    cout<<"商店老板对你上下打量，对你说"<<endl;
    cout<<"小伙子，我看你骨骼惊奇，似乎有武林高手之相，我等的就是你啊！"<<endl;
    cout<<"------------------------------------------------------"<<endl;
    cout<<"商品价格"<<setw(19)<<"商品名称"<<setw(19)<<"商品序号"<<setw(19)<<"购买条件\n";
    cout<<"50"<<setw(19)<<"铜制短剑"<<setw(19)<<"1"<<setw(19)<<"lv5\n";
    cout<<"100"<<setw(19)<<"千年何首乌"<<setw(19)<<"2"<<setw(19)<<"无\n";
    cout<<"200"<<setw(19)<<"红花人参"<<setw(19)<<"2"<<setw(19)<<"无\n";
    cout<<"------------------------------------------------------"<<endl;
    cout<<"要买点什么嘛，按Y掏出钱包\n";
    cin>>x;
    if (x=='y')
        Buy();
    else
        cout<<"你摸了摸自己干瘪的钱包"<<endl;
        cout<<"还是快点走吧"<<endl;
    }
void Buy(){
    cout<<"你四下看看，打算买点什么\n";
    cin>>x;
    switch (x) {
        case '1':
            Money-=50;
            cout<<"你购买了这把上好的宝剑，花费了50金"<<endl;
            MyStrong+=50;
            cout<<"你的战斗力增加了50点，非常高兴\n";
        case '2':
            Money-=100;
            cout<<"你看见了这千年何首乌十分心动，孤注一掷，花了100金买了一根\n";
            experience+=1000;
            Upgrate();
        case '3':
            Money-=200;
            cout<<"这红花人参抓住了你的眼镜\n";
            WuPoint+=1;
            cout<<"在囫囵吞下之后，你的悟性增加了1点，十分开心\n";
    }
    cout<<"在慷慨解囊之后，你神清气爽，匆匆离开了商店\n";
}
//(rand() % (b-a))+ a + 1) (a,b]
//要取得[a,b]的随机整数，使用(rand() % (b-a+1))+ a;

