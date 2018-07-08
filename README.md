<!---
    
-->

# Arduino智能小车

## 硬件

* 使用ESP8266-12F作为小车MCU控制系统，方便WiFi控制
* L298N点击驱动，驱动左右轮点击正反转PWM调速等供能

## 软件

* ESP8266-12F使用Arduino编程
* 远端控制使用Androoid手机
* 服务器使用apache-apollo-1.7.1
* 硬件、软件、服务器数据交互使用MQTT协议

## LICENSE

         MIT License

    Copyright (c) 2018 Ice Lee

    Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.