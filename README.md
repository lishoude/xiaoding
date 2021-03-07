#立创&涂鸦-物联网温湿度传感器
===============================
This project is developed using Tuya SDK, which enables you to quickly develop branded apps connecting and controlling smart scenarios of many devices.
For more information, please check Tuya Developer Website.
一、作品简介

       作品采用MCU控制，实现在屏幕上显示温度湿度，并把温度湿度数据上传至云端通过APP显示。

       自己弄了两个亚克力板，作为外壳（用钻头打孔太难了，打的有点偏）

       因为温湿度计，所以主要以一个温度计的模型来设计，做完后发现效果一般（哈哈哈，不过自己感觉也还行，没有偏差太多）

      1、使用的主要器件：主控（stm32f103c8t6）、显示模块（0.91寸OLED显示屏）、涂鸦WB3S模块
      2、下载使用的串口1，涂鸦模块使用串口2

二、功能描述

       1、两个指示灯，pow指示灯为绿色电源指示灯，当通电后亮，断电后灭，LED为状态标志指示灯（亮灭状态在下面展示），细节如下图：

       2、有4个按键，分别为复位、上翻、下翻、确定，复位：程序复位，上翻下翻：用来切换屏幕显示温度或者湿度。确定按键：用来配置网络，点击按键，进入配网状态， 处于 Smart 配置状态，即 LED 快闪；处于 AP 配置状态，即 LED 慢闪 ;Wi-Fi 配置完成，正在连接路由器，即 LED 常暗；路由器连接成功，即 LED 常亮。
       3、OLED显示，有温度和湿度两种显示状态
三、器件简介

             温湿度传感器  :  sht30模块，（这个是真的小，焊接时看的眼疼，因为只有一个，我以为底部没有焊接好，还拆过一次，然后又焊接上，还好没有坏，胆战心惊）

             显示模块：0.91寸OLED，正好和电子温度计的显示屏差不多大小。

             电源稳压：AMS1117-3.3（头一次用，挺好使）

             涂鸦WB3S：（这个就太有意思了，看着那么难，琢么了好久都没弄成，然后突然开窍，一路使用通畅）

             主控（stm32f103c8t6）:因为以前使用过这个，相对容易些，但都一次焊接这么多引脚的贴片，嘿嘿，挑战下自己
     
四、设备和APP连接方法：

         按确认按键，LED闪烁，

         打开涂鸦智能APP，搜索，我一般使用自动搜素

         然后连接成功输入WiFi密码

         就完成了

 

五、链接
     实物图片、视频、PCB等链接：https://oshwhub.com/Hello_XiaoDing/wu-lian-wang-wen-shi-du-ji

      通过这次实训，我完成了自己的第一个画电路板的作品，有很多困难，但是能做出来真的开心。

      感谢立创&涂鸦~
