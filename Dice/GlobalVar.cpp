/*
 *  _______     ________    ________    ________    __
 * |   __  \   |__    __|  |   _____|  |   _____|  |  |
 * |  |  |  |     |  |     |  |        |  |_____   |  |
 * |  |  |  |     |  |     |  |        |   _____|  |__|
 * |  |__|  |   __|  |__   |  |_____   |  |_____    __
 * |_______/   |________|  |________|  |________|  |__|
 *
 * Dice! QQ Dice Robot for TRPG
 * Copyright (C) 2018-2019 w4123溯洄, 杏牙
 *
 * This program is free software: you can redistribute it and/or modify it under the terms
 * of the GNU Affero General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this
 * program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "CQLogger.h"
#include "GlobalVar.h"
#include <map>

bool Enabled = false;

bool msgSendThreadRunning = false;

CQ::logger DiceLogger("Dice!");

/*
 * 版本信息
 * 请勿修改Dice_Build, Dice_Ver_Without_Build，DiceRequestHeader以及Dice_Ver常量
 * 请修改Dice_Short_Ver或Dice_Full_Ver常量以达到版本自定义
 */
const unsigned short Dice_Build = 509;
const std::string Dice_Ver_Without_Build = "2.3.6";
const std::string DiceRequestHeader = "Dice/" + Dice_Ver_Without_Build;
const std::string Dice_Ver = Dice_Ver_Without_Build + "(" + std::to_string(Dice_Build) + ")";
const std::string Dice_Short_Ver = "Dice! by 溯洄,杏牙 Version " + Dice_Ver;
const std::string Dice_Full_Ver = Dice_Short_Ver + " [MSVC " + std::to_string(_MSC_FULL_VER) + " " + __DATE__ + " " + __TIME__ + "]";
//GlobalMsg["strGetCardCatMessage"]
std::map<std::string, std::string> GlobalMsg
{
	{"",""},
	{"strGetBook1","恭喜您抽中了：《世界观(英文版)》\n“喵！好厉害”（本猫对你的崇拜度+0.6，同情度-0.3）" },
	{"strGetBook2","恭喜您抽中了：《牧猫人手册(英文版)》\n“喵！好厉害”（本猫对你的崇拜度+0.4，同情度-0.2）" },
	{"strGetBook3","恭喜您抽中了：《猫之书(英文版)》\n“运气不错嘛!”（本猫对你的崇拜度+0.2，同情度-0.1）" },
	{"strGetBook4","恭喜您抽中了：《基础规则》\n“记得好好学习喵~”（本猫对你的崇拜度+0.1）" },
	{"strNoExtractionTime","抱歉，您今天的抽取次数已经用完。请明天再试。" },
	{"strExtractNothing","抱歉，你没有抽中任何图书\n“别灰心~喵”（本猫对你的同情度+0.3）" },
	{"strGetBookMailTitle","书是喵咪们进步的阶梯" },
	{"strGetCardHumanMailTitle","人物卡模板1.3.2版" },
	{"strGetCardCatMailTitle","喵卡模板1.0.0版" },
	{"strGetBookMailContent","这是您抽到的书哟~\n记得回复一下邮件哟，不然以后我发的邮件会被爸爸扔进垃圾桶的。" },
	{"strGetCardHumanMailContent","附件为人物卡模板。欢迎提出意见" },
	{"strGetCardCatMailContent","附件为喵卡模板。欢迎提出意见" },
	{"strGetCardHumanMessage","人物卡模板1.3.2版已经发到你的邮箱啦~~\n记得回复一下邮件哟，不然以后我发的邮件会被爸爸扔进垃圾桶的。" },
	{"strGetCardCatMessage","喵卡模板1.0.0版已经发到你的邮箱啦~~\n记得回复一下邮件哟，不然以后我发的邮件会被爸爸扔进垃圾桶的。" },
	{"pathCardOfHuman","F:\\人物卡空白模板.xlsx"},
	{"pathCardOfCat","F:\\喵卡coc7模板.xlsx"},
	{"pathBook1","F:\\Call of Catthulhu, Book III - Worlds of Catthulhu.pdf"},
	{"pathBook2","F:\\Call of Catthulhu, Book II - UNAUSSPRECHLICHEN KATZEN (The Cat Herders Guide).pdf"},
	{"pathBook3","F:\\Call of Catthulhu, Book I - THE NEKONOMIKON (The Book of Cats).pdf"},
	{"pathBook4","F:\\喵苏鲁基础规则.doc"},
	{"strLogNotSupportPrivateChat","日志记录指令仅在群里起作用，私聊中无效" },

	{"strNameNumTooBig", "生成数量过多!请输入1-10之间的数字!"},
	{"strNameNumCannotBeZero", "生成数量不能为零!请输入1-10之间的数字!"},
	{"strSetInvalid", "无效的默认骰!请输入1-99999之间的数字!"},
	{"strSetTooBig", "默认骰过大!请输入1-99999之间的数字!"},
	{"strSetCannotBeZero", "默认骰不能为零!请输入1-99999之间的数字!"},
	{"strCharacterCannotBeZero", "人物作成次数不能为零!请输入1-10之间的数字!"},
	{"strSetInvalid", "无效的默认骰!请输入1-99999之间的数字!"},
	{"strSetTooBig", "默认骰过大!请输入1-99999之间的数字!"},
	{"strSetCannotBeZero", "默认骰不能为零!请输入1-99999之间的数字!"},
	{"strCharacterCannotBeZero", "人物作成次数不能为零!请输入1-10之间的数字!"},
	{"strCharacterTooBig", "人物作成次数过多!请输入1-10之间的数字!"},
	{"strCharacterInvalid", "人物作成次数无效!请输入1-10之间的数字!"},
	{"strSCInvalid", "SC表达式输入不正确,格式为成功扣San/失败扣San,如1/1d6!"},
	{"strSanInvalid", "San值输入不正确,请输入1-99范围内的整数!"},
	{"strEnValInvalid", "技能值或属性输入不正确,请输入1-99范围内的整数!"},
	{"strGroupIDInvalid", "无效的群号!"},
	{"strSendErr", "消息发送失败!"},
	{"strDisabledErr", "命令无法执行:机器人已在此群中被关闭!"},
	{"strMEDisabledErr", "管理员已在此群中禁用.me命令!"},
	{"strHELPDisabledErr", "管理员已在此群中禁用.help命令!"},
	{"strNameDelErr", "没有设置名称,无法删除!"},
	{"strValueErr", "掷骰表达式输入错误!"},
	{"strInputErr", "命令或掷骰表达式输入错误!"},
	{"strUnknownErr", "发生了未知错误!"},
	{"strUnableToGetErrorMsg", "无法获取错误信息!"},
	{"strDiceTooBigErr", "骰娘被你扔出的骰子淹没了"},
	{"strRequestRetCodeErr", "访问服务器时出现错误! HTTP状态码: {0}"},
	{"strRequestNoResponse", "服务器未返回任何信息"},
	{"strTypeTooBigErr", "哇!让我数数骰子有多少面先~1...2..."},
	{"strZeroTypeErr", "这是...!!时空裂(骰娘被骰子产生的时空裂缝卷走了)"},
	{"strAddDiceValErr", "你这样要让我扔骰子扔到什么时候嘛~(请输入正确的加骰参数:5-10之内的整数)"},
	{"strZeroDiceErr", "咦?我的骰子呢?"},
	{"strRollTimeExceeded", "掷骰轮数超过了最大轮数限制!"},
	{"strRollTimeErr", "异常的掷骰轮数"},
	{"strWelcomeMsgClearNotice", "已清除本群的入群欢迎词"},
	{"strWelcomeMsgClearErr", "错误:没有设置入群欢迎词，清除失败"},
	{"strWelcomeMsgUpdateNotice", "已更新本群的入群欢迎词"},
	{"strPermissionDeniedErr", "错误:此操作需要群主或管理员权限"},
	{"strNameTooLongErr", "错误:名称过长(最多为50英文字符)"},
	{"strUnknownPropErr", "错误:属性不存在"},
	{"strEmptyWWDiceErr", "格式错误:正确格式为.w(w)XaY!其中X≥1, 5≤Y≤10"},
	{"strPropErr", "请认真的输入你的属性哦~"},
	{"strSetPropSuccess", "属性设置成功"},
	{"strPropCleared", "已清除所有属性"},
	{"strRuleErr", "规则数据获取失败,具体信息:\n"},
	{"strRulesFailedErr", "请求失败,无法连接数据库"},
	{"strPropDeleted", "属性删除成功"},
	{"strPropNotFound", "错误:属性不存在"},
	{"strRuleNotFound", "未找到对应的规则信息"},
	{"strProp", "{0}的{1}属性值为{2}"},
	{"strStErr", "格式错误:请参考帮助文档获取.st命令的使用方法"},
	{"strRulesFormatErr", "格式错误:正确格式为.rules[规则名称:]规则条目 如.rules COC7:力量"},
	{"strJrrp", "{0}今天的人品值是: {1}"},
	{"strJrrpErr", "JRRP获取失败! 错误信息: \n{0}"},
	{"strGetBookCatInfo", "【喵苏鲁图书抽取 - 抽中概率】\n《基础规则》         -30%\n《猫之书(英文版)》      - 10 % \n《牧猫人手册(英文版)》 - 2 % \n《世界观(英文版)》   - 0.4%\n《血光将至log》by杏子 - 0.2%\n《猫之书(中文版)》   - 0.05% \n《牧猫人手册(中文版)》 - 0.01 % \n《世界观(中文版)》    - 0.003 % \n"},
	{"strHlpMsg" , Dice_Short_Ver + "\n" +
	R"((本骰子为暂为测试版本。目录为：【扩展指令·喵苏鲁】、【扩展指令·log记录】、【测试版说明】、【扩展指令解惑】、【通用指令】)
【扩展指令·喵苏鲁】
.cat [个数]              喵苏鲁猫咪做成
.getcard human     获取人物卡模板
.getcard cat           获取喵卡模板
.getbook cat          获取喵苏鲁游戏规则书
【扩展指令·log记录】
.log on Name       开始记录名为Name的log
.log off                停止记录log
.log get Name      获取所有以Name开始的log记录
.begin Name         .log on Name 指令的简化
.end                      .log off 指令的简化
.get Name             .log get Name 指令的简化
【测试版说明】
如果发现bug或有意见、建议等，欢迎私聊告诉本骰子。
如果你有想共享给其他人的文件，可以直接私聊发给本骰子。审核通过后将加入到“getbook”指令中。
【扩展指令解惑】
.cat                随机生成一只猫的属性
.cat 5             随机生成五只猫的属性
.begin 模组：喵苏鲁-主线    开始记录名为“模组：喵苏鲁-主线”的log
.begin 模组：喵苏鲁-支线    开始记录名为“模组：喵苏鲁-支线”的log
.get 模组：喵苏鲁-主线        获取到名为“模组：喵苏鲁-主线”的log记录
.get 模组：喵苏鲁                同时获取到“模组：喵苏鲁-主线”和“模组：喵苏鲁-支线”的log记录
【通用命令】
请使用!dismiss [机器人QQ号]命令让机器人自动退群或讨论组！
跑团记录着色器: https://logpainter.kokona.tech
.r [掷骰表达式*] [原因]			普通掷骰
.rs	[掷骰表达式*] [原因]			简化输出
.w/ww XaY						骰池
.set [1-99999之间的整数]			设置默认骰
.sc SC表达式** [San值]			自动Sancheck
.en [技能名] [技能值]			增强检定/幕间成长
.coc7/6 [个数]					COC7/6人物作成
.dnd [个数]					DND人物作成
.coc7/6d					详细版COC7/6人物作成
.ti/li					疯狂发作-临时/总结症状
.st [del/clr/show] [属性名] [属性值]		人物卡导入
.rc/ra [技能名] [技能值]		技能检定(规则书/房规)
.jrrp [on/off]				今日人品检定
.name [cn/jp/en] [个数]			生成随机名称
.rules [规则名称:]规则条目		规则查询
.help						显示帮助
<仅限群/多人聊天>
.ri [加值] [昵称]			DnD先攻掷骰
.init [clr]					DnD先攻查看/清空
.nn [名称]					设置/删除昵称
.nnn [cn/jp/en]				随机设置昵称
.rh [掷骰表达式*] [原因]			暗骰,结果私聊发送
.bot [on/off] [机器人QQ号]		机器人开启或关闭
.ob [exit/list/clr/on/off]			旁观模式
.me on/off/动作				以第三方视角做出动作
.welcome 欢迎消息				群欢迎提示
<仅限私聊>
.me 群号 动作				以第三方视角做出动作
*COC7惩罚骰为P+个数,奖励骰为B+个数
 支持使用K来取较大的几个骰子
 支持使用 个数#表达式 进行多轮掷骰
**SC表达式为 成功扣San/失败扣San,如:1/1d6
插件交流/bug反馈/查看源代码请加QQ群941980833或624807593(已满))"}
};