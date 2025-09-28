# 51-

温度监测系统：片内RAM暂存，片外RAM长期保存；关键值通过I/O口显示/报警；支持偏移修正、平均、最大/最小值、阈值报警与范围判断。  Real-time lab temperature monitoring: on-chip RAM for temporary data, off-chip RAM for storage; critical values via I/O display/alarm; supports offset correction, averaging, max/min detection, threshold alert, and range check. Designed for embedded data acquisition and monitoring.



\# 实验室温度监测系统



\## 📌 项目背景



在实验室环境中，需要对温度进行实时监测。由于片内 RAM 容量有限，只能用于暂存数据，长期保存必须依赖片外 RAM。同时，关键温度值需要通过 I/O 接口实时显示或触发报警，提示使用者采取措施。



本系统基于 51 单片机与 Keil 开发环境实现，涵盖数据采集、存储、显示与运算，适用于嵌入式数据采集与监测实验。



---



\## ⚙️ 系统功能



1\. \*\*数据采集与存储\*\*



&nbsp;  \* 采集温度数据并暂存于片内 RAM

&nbsp;  \* 批量传送至片外 RAM，用于长期保存



2\. \*\*关键值显示与报警\*\*



&nbsp;  \* 将关键值输出到 I/O 口（LED 显示/报警）

&nbsp;  \* 超过阈值时，触发 LED 报警信号



3\. \*\*算术与逻辑运算\*\*



&nbsp;  \* \*\*移位/偏移修正\*\*：温度数据读取后统一加上 ±1，模拟传感器误差修正

&nbsp;  \* \*\*平均值\*\*：多次读取后取平均值，再存入片外 RAM

&nbsp;  \* \*\*最大值/最小值\*\*：在片内 RAM 批量数据中计算，并输出关键数据

&nbsp;  \* \*\*阈值判断\*\*：若温度超过设定阈值，输出报警

&nbsp;  \* \*\*逻辑判断\*\*：检测温度是否处于合理范围



---



\## 📂 项目结构



```

51-project/

│── src/                # 源码目录

│    ├── main.c         # 主程序（温度采集与运算逻辑）

│    ├── temp.c         # 温度数据处理模块

│    ├── temp.h         # 头文件

│

│── project1.uvproj     # Keil 工程文件

│── .gitignore          # 忽略规则（不提交编译产物）

│── README.md           # 项目说明

```



---



\## 🚀 使用说明



1\. 使用 \*\*Keil uVision\*\* 打开 `project1.uvproj` 工程文件。

2\. 编译工程，生成 `.hex` 文件。

3\. 将程序下载至 51 单片机硬件平台。

4\. 通过 \*\*LED 指示/报警\*\* 或串口调试工具查看运行结果。



---



\## 📖 致谢



本项目用于课程实验与学习，展示了基于单片机的 \*\*数据采集、存储与逻辑处理\*\* 的实现方法。



\# Laboratory Temperature Monitoring System



\## 📌 Project Background



In a laboratory environment, real-time temperature monitoring is required. Since the on-chip RAM is limited and can only be used for temporary storage, long-term data must be saved in off-chip RAM. At the same time, critical temperature values need to be displayed via I/O ports or trigger alarms to remind users to take action.



This system is implemented on the 8051 microcontroller using the Keil development environment. It covers data acquisition, storage, display, and processing, suitable for embedded data collection and monitoring experiments.



---



\## ⚙️ System Features



1\. \*\*Data Acquisition \& Storage\*\*



&nbsp;  \* Acquire temperature data and temporarily store it in on-chip RAM

&nbsp;  \* Transfer data in batches to off-chip RAM for long-term storage



2\. \*\*Key Value Display \& Alarm\*\*



&nbsp;  \* Output critical values to I/O ports (LED display/alarm)

&nbsp;  \* Trigger LED alarm when threshold is exceeded



3\. \*\*Arithmetic \& Logic Operations\*\*



&nbsp;  \* \*\*Offset Correction\*\*: Add ±1 to temperature values to simulate sensor error correction

&nbsp;  \* \*\*Averaging\*\*: Store the average of multiple readings into off-chip RAM

&nbsp;  \* \*\*Max/Min Detection\*\*: Compute max/min values from a batch of data in on-chip RAM and output as key data

&nbsp;  \* \*\*Threshold Judgment\*\*: Trigger alarm if temperature exceeds preset threshold

&nbsp;  \* \*\*Range Check\*\*: Verify whether temperature is within a reasonable range



---



\## 📂 Project Structure



```

51-project/

│── src/                # Source code directory

│    ├── main.c         # Main program (temperature acquisition \& logic)

│    ├── temp.c         # Temperature data processing module

│    ├── temp.h         # Header file

│

│── project1.uvproj     # Keil project file

│── .gitignore          # Ignore rules (exclude build artifacts)

│── README.md           # Project documentation

```



---



\## 🚀 Usage Instructions



1\. Open `project1.uvproj` with \*\*Keil uVision\*\*.

2\. Compile the project to generate the `.hex` file.

3\. Download the program to the 8051 microcontroller hardware.

4\. Observe results via \*\*LED indicators/alarms\*\* or serial debugging tools.



---



\## 📖 Acknowledgment



This project is designed for course experiments and learning, demonstrating how to implement \*\*data acquisition, storage, and logic processing\*\* based on microcontrollers.





