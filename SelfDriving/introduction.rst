.. morpx documentation master file, created by
   sphinx-quickstart on Fri Jul 19 17:00:19 2019.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

MU Self-driving Kit Introduction
=======================

MU 视觉传感器3（MU Vision Sensor 3）是一款用于图像识别的传感器，其内置的深度学习引擎可以识别多种目标物体，
例如颜色检测、球体检测、人体检测、卡片识别等。检测结果可以通过 UART 或 I2C 进 行输出，体积小巧，功耗低，
所有算法本地处理，无须联网，可广泛应用于智能玩具、人工智能 教具、创客等产品或领域。

.. image:: images/MUVS3_main.png

硬件设置
--------

1. 设置通讯模式
+++++++++++++++

MU 支持 4 种通讯模式: ``UART,I2C,WIFI,图传`` 模式。根据所需要的通讯方式,拨动 MU 左侧的 ``Output`` 拨码开关。

选择通讯方式后,程序中的通讯方式应与拨码开关保持一致。编程时应首先配置通讯方式,
然后才可以进行其他的参数配置,使用过程中不可更改,每次切换通讯方式,需要重启小 MU。

.. |FUNC00| image:: images/mu3_func_switch_00.png
   :height: 46
   :width: 30

.. |FUNC01| image:: images/mu3_func_switch_01.png
   :height: 46
   :width: 30

.. |FUNC10| image:: images/mu3_func_switch_10.png
   :height: 46
   :width: 30

.. |FUNC11| image:: images/mu3_func_switch_11.png
   :height: 46
   :width: 30

+----------+----------+------+----------+
| 输出模式 | 拨码开关 | 编号 | LED 指示 |
+==========+==========+======+==========+
|   UART   | |FUNC00| |  00  | 闪烁红色 |
+----------+----------+------+----------+
|   I2C    | |FUNC01| |  01  | 闪烁绿色 |
+----------+----------+------+----------+
|   WiFi   | |FUNC10| |  10  | 闪烁黄色 |
+----------+----------+------+----------+
|   图传   | |FUNC11| |  11  | 闪烁紫色 |
+----------+----------+------+----------+

2. 设置地址
+++++++++++

MU 支持 4 个地址:0x60(默认),0x61,0x62,0x63。当 MU 与其他传感器地址冲突时需要进行更改。
I2C 模式下支持多个不同地址的 MU 协同工作,可以给 MU 分配不同的地址。

.. note::

    一般情况下使用默认地址 ``0x60`` 即可。

+----------+----------+------+----------+----------+------+
| 设备地址 | 拨码开关 | 编号 | 设备地址 | 拨码开关 | 编号 |
+==========+==========+======+==========+==========+======+
|   0x60   | |FUNC00| |  00  |   0x61   | |FUNC01| |  01  |
+----------+----------+------+----------+----------+------+
|   0x62   | |FUNC10| |  10  |   0x63   | |FUNC11| |  11  |
+----------+----------+------+----------+----------+------+

3. 线路连接
+++++++++++

:UART/WiFi/图传 模式:

    +------+----+----+-----+----+
    | MU   | RX | TX | G   | V  |
    +------+----+----+-----+----+
    | 主控 | TX | RX | GND | 5V |
    +------+----+----+-----+----+

:I2C 模式:

    +------+-----+-----+-----+----+
    |  MU  | SCL | SDA |  G  | V  |
    +------+-----+-----+-----+----+
    | 主控 | SCL | SDA | GND | 5V |
    +------+-----+-----+-----+----+

软件设置
--------

详见本目录下各平台对应教程。

特殊模式介绍
------------

.. _wifi-connect:

WiFi/图传模式配网
++++++++++++++++++++

WiFi/图传模式可通过向 MU 发送 AT 指令的方式进行配网，串口默认波特率为9600。

可通过输入以下指令获取所有 AT 指令：

.. code-block:: shell

    AT+HELP

.. attention::

    所有指令必须以 ``"\r\n"`` 或 ``' '`` 结尾

MU 可支持 ``AP`` 模式联网和 ``STA`` 模式联网，两种联网区别如下：

:AP 模式:

    ``AP`` 模式为 MU 默认的 WiFi 模式，该模式下 MU 会生成一个 WiFi 热点，用户使用手机或电脑去连接此热点即可。
    WiFi 成功连接后，MU 的 LED 就会熄灭。

    默认的热点名称为 ``MORPX-MU-AB`` 。

    .. note::

        WiFi 名称中 ``A`` 为 MU 左侧 LED 颜色的首字母，``B`` 为右侧 LED 颜色的首字母。

        （如：左侧 LED 为红色 **R** ed， 右侧为黄色 **Y** ellow，则默认 WiFi 名称为 ``MORPX-MU-RY``）

    若需要自定义 WiFi 名称，可通过串口发送以下指令进行配置：

    .. code-block:: shell

        AT+WIFISET=<yourSSID>,<yourPassword>,AP
        AT+WIFICON=1

    若设置成功，则返回：

    .. code-block:: shell

        OK
        wifi ap mode starting...
        OK

:STA 模式:

    ``STA`` 模式需要 MU 和用户的设备去连接一个公共的 WiFi，以实现二者的互联。
    可通过串口发送以下指令进行配置：

    .. code-block:: shell

        AT+WIFISET=<yourSSID>,<yourPassword>,STA
        AT+WIFICON=1

    .. attention::

        ``<yourSSID>`` 和 ``<yourPassword>`` 必须是一个已存在的 WiFi（区分大小写），否则会连接失败。

    若设置成功，则返回：

    .. code-block:: shell

        OK
        wifi sta mode connecting...
        OK

图传模式图像查看
++++++++++++++++

将 MU 设置成图传模式及完成 :ref:`配网 <wifi-connect>` 后，可通过打开网址 ``192.168.4.1`` 查看图像。

无线透传
++++++++

WiFi/图传模式皆可进行无线透传，完成 :ref:`配网 <wifi-connect>` 后，可通过以下方式来进行无线透传：

    .. note::

        因为手机、电脑不同平台，不同操作系统下 TCP/UDP 调试软件各不相同，软件的设置方式大同小异，这里定义以下几个名词：

        - ``本地 IP`` : 即 MU 的 IP 地址
        - ``目标 IP`` : 即 MU 需要发送消息的目标设备的 IP 地址

    1. 打开 TCP/UDP 调试软件，选择 ``UDP``，将模式设置为 ``Unicast``
    2. 查询本地 IP，通过串口向 MU 发送指令：

    .. code-block:: shell

        AT+WIFISIP

    返回 MU 的本地 IP。

    3. 将 TCP/IP IP 栏设置为 MU 的本地 IP， 端口设置为 ``3333``

    .. note::

        STA 模式下路由会为 MU 和目标设备随机分配一个 IP 地址，需要通过以下方式配置：

        1. 查询目标 IP （大多 TCP/IP 软件会显示当前设备的 IP 地址）
        2. 通过串口向 MU 发送指令：

        .. code-block:: shell

            AT+WIFIUDP=<targetIP>,3333

        返回：

        .. code-block:: shell

            OK

至此，WiFi 配置完毕，TCP/UDP 调试软件发送的所有数据会通过 MU 的串口转发出来，
通过串口向 MU 发送的所有数据也会在 TCP/UDP 调试软件的监视器上显示出来。
