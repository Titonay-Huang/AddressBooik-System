#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "functions.h"
#include "AddressList.h"
#define MAX_LENGTH 50

int main()
{
    int status=0;
    char input[MAX_LENGTH], t;
    while(1)
    {
        if(status==0)
        {
            printf("\n");
            printf("    ********************************************************\n");
            printf("    *                                                      *\n");
            printf("    *      请先登录通讯录管理系统，若无账户请先注册        *\n");
            printf("    *        1、注册                      2、登录          *\n");
            printf("    *        3、管理员登陆                4、退出          *\n");
            printf("    *                                                      *\n");
            printf("    *      ##请注意：输入过程中不可以有任何的空格哦##      *\n");
            printf("    *                                                      *\n");
            printf("    ********************************************************\n");
            printf("        请输入您需要的功能编号：");
            scanf("%c", &t);
            getchar();
            switch(t)
            {
                case '1' :
                    root_Power();
                    break;
                case '2' :
                    if(user_Signin()==1) status=1;
                    break;
                case '3' :
                    if(root_Signin()==1) status=2;
                    break;
                case '4' :
                    exit(0);
                default:
                    printf("\n        < 暂时无此命令 >\n");
                    break;
            }

        }

        else if(status == 1)
        {
            printf("\n");
            printf("    ********************************************************\n");
            printf("    *                                                      *\n");
            printf("    *     用户 %-20s 你好，请选择功能：                    *\n", face);
            printf("    *       1、查找联系人               2、增加联系人      *\n");
            printf("    *       3、列出所有联系人           4、列出标签种类    *\n");
            printf("    *       5、查看标签内联系人         6、退出登录        *\n");
            printf("    *                                                      *\n");
            printf("    *      ##请注意：输入过程中不可以有任何的空格哦##      *\n");
            printf("    *  ##如需要删除联系人或者修改联系人信息请联系管理员##  *\n");
            printf("    *                                                      *\n");
            printf("    ********************************************************\n");
            printf("        请输入您需要的功能编号：");
            scanf("%c", &t);
            getchar();
            switch(t)
            {
                case '1' :
                    printf("        请输入你要查看的联系人的名字：");
                    scanf("%s", input);
                    ElasticSearch(input);
                    break;
                case '2' :
                    EnterAddress();
                    break;
                case '3' :
                    LoadAddress();
                    break;
                case '4' :
                    LoadCategory();
                    break;
                case '5' :
                    CheckCategory();
                    break;
                case '6' :
                    status=0;
                    printf("\n        < 退出登录成功 >\n");
                    break;
                default:
                    printf("\n        < 暂时无此命令 >\n");
                    break;
            }
        }
        else if(status == 2)
        {
            printf("\n");
            printf("    ********************************************************\n");
            printf("    *                                                      *\n");
            printf("    *     管理员模式，请选择所需要的功能：                 *\n");
            printf("    *       1、更改管理员密码           2、增加用户        *\n");
            printf("    *       3、删除用户                 4、查看用户列表    *\n");
            printf("    *       5、修改联系人信息           6、删除联系人      *\n");
            printf("    *       7、退出登录                                    *\n");
            printf("    *                                                      *\n");
            printf("    *      ##请注意：输入过程中不可以有任何的空格哦##      *\n");
            printf("    *                                                      *\n");
            printf("    ********************************************************\n");
            printf("        请输入您需要的功能编号：");
            scanf("%c", &t);
            getchar();
            switch(t)
            {
                case '1' :
                    rewriteRootPasswd();
                    break;
                case '2' :
                    Register();
                    break;
                case '3' :
                    Deluser();
                    break;
                case '4' :
                    Loaduser();
                    break;
                case '5' :
                    printf("        请输入要修改的联系人名字：");
                    scanf("%s", input);
                    if(ModifyAddress(input)!=-1) printf("\n        < 联系人信息修改成功 >\n");
                    else                         printf("\n        < 联系人不存在，修改信息失败,请输入完整的名字 >\n");
                    break;
                case '6' :
                    DelAddress();
                    break;
                case '7' :
                    status=0;
                    printf("\n        < 退出登录成功 >\n");
                    break;
            }
        }

    }
    return 0;
}
