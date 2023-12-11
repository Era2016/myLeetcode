// http://data.biancheng.net/view/147.html
//

//#include <iostream>
//const int CHN_CHAR_LENGTH = 4;

//typedef struct {
    //const char *name; //中文权位名称
    //int value; //10的倍数值
    //bool secUnit; //是否是节权位
//}CHN_NAME_VALUE;

//CHN_NAME_VALUE chnValuePair[]={ {"十",10, false }, {"百", 100, false }, {"千", 1000, false }, {"万"，10000, true }, {"亿",100000000, true }};

//unsigned int ChineseToNumber(const std::string& chnString)
//{
    //unsigned int rtn = 0;
    //unsigned int section = 0;
    //int number = 0;
    //bool secUnit = false;
    //std::string::size_type pos = 0;
    //while(pos < chnString.length())
    //{
        //int num = ChineseToValue(chnString.substr(pos, CHN_CHAR_LENGTH));
        //if(num >= 0) /*数字还是单位？ */
        //{
            //number = num;
            //pos += CHN_CHAR_LENGTH;
            //if (pos >= chnString.length())//如果是最后一位数字，直接结束
            //{
                //section += number;
                //rtn += section;
                //break;
            //}
        //}
        //else
        //{
            //int unit = ChineseToUnit(chnString.substr(pos,CHN_CHAR_LENGTH), secUnit);
            //if(SeCUnit)//是节权位说明一个节己经结束
            //{
                //section = (section + number) * unit;
                //rtn += section;
                //section = 0;
            //}
            //else
            //{
                //section += (number * unit);
            //}
            //number = 0;
            //pos += CHN_CHAR_LENGTH;
            //if(pos >= chnString.length())
            //{
                //rtn += section;
                //break;
            //}
        //}
    //}
    //return rtn;
//}
