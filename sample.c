int main(int argc, char* argv[])

{

int        ret                  = MSP_SUCCESS;

const char* login_params        = "appid = 56ee43d0, work_dir = .";//登录参数,appid与msc库绑定,请勿随意改动

/*

* rdn:          合成音频数字发音方式

* volume:        合成音频的音量

* pitch:        合成音频的音调

* speed:        合成音频对应的语速

* voice_name:    合成发音人

* sample_rate:  合成音频采样率

* text_encoding: 合成文本编码格式

*

* 详细参数说明请参阅《iFlytek MSC Reference Manual》

*/

const char* session_begin_params = "voice_name = xiaoyan, text_encoding = UTF8, sample_rate = 16000, speed = 50, volume = 50, pitch = 50, rdn = 2";

const char* filename            = "tts_sample.wav"; //合成的语音文件名称

const char* text                = "亲爱的用户，您好，这是一个语音合成示例，感谢您对科大讯飞语音技术的支持！科大讯飞是亚太地区最大的语音上市公司，股票代码：002230"; //合成文本

if(argc < 2)

{

printf("usage:tts_sample 测试\n");

return -1;

}

text = argv[1];

/* 用户登录 */

ret = MSPLogin(NULL, NULL, login_params);//第一个参数是用户名，第二个参数是密码，第三个参数是登录参数，用户名和密码可在http://open.voicecloud.cn注册获取

if (MSP_SUCCESS != ret)

{

printf("MSPLogin failed, error code: %d.\n", ret);

goto exit ;//登录失败，退出登录

}

printf("\n###########################################################################\n");

printf("## 语音合成（Text To Speech，TTS）技术能够自动将任意文字实时转换为连续的 ##\n");

printf("## 自然语音，是一种能够在任何时间、任何地点，向任何人提供语音信息服务的  ##\n");

printf("## 高效便捷手段，非常符合信息时代海量数据、动态更新和个性化查询的需求。  ##\n");

printf("###########################################################################\n\n");

/* 文本合成 */

printf("开始合成 ...\n");

ret = text_to_speech(text, filename, session_begin_params);

if (MSP_SUCCESS != ret)

{

printf("text_to_speech failed, error code: %d.\n", ret);

goto exit ;

}

printf("合成完毕\n");

system("mplayer tts_sample.wav");

exit:

//printf("按任意键退出 ...\n");

//getchar();

MSPLogout(); //退出登录

return 0;

}