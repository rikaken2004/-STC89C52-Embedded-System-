# -STC89C52-Embedded-System-
"A comprehensive embedded system based on STC89C52 
# STC89C52 多功能嵌入式系统

## 项目概述

本项目是一个基于STC89C52单片机的综合嵌入式系统，展示了从基础IO控制到复杂系统集成的完整开发流程。系统集成了数字显示、状态指示、用户交互和机电控制，体现了硬件资源优化和系统架构设计能力。

## 核心功能

### 智能计数系统
- **多级显示**：四位数码管显示总数，两位数码管显示批次计数和目标值
- **自动分拣**：达到设定数量时自动启动电机进行分拣
- **状态指示**：6个LED提供丰富的视觉反馈

### 硬件特性
- **引脚复用**：在有限的32个I/O口上驱动8位数码管+6个LED+传感器+电机
- **动态扫描**：所有数码管采用快速扫描技术，显示稳定无闪烁
- **独立供电**：电机驱动使用独立电源，确保系统稳定性

### 软件架构
- **模块化设计**：显示、输入、控制逻辑分离
- **状态机管理**：清晰的项目状态流转
- **防抖动处理**：可靠的用户输入检测

## 技术栈

### 硬件平台
- 主控芯片：STC89C52RC
- 显示模块：2×两位数码管 + 1×四位数码管
- 驱动模块：L298N电机驱动器
- 输入设备：红外传感器/按钮

### 开发环境
- IDE：Keil μVision 5
- 编译工具：C51编译器
- 下载工具：STC-ISP

## 快速开始

### 硬件准备
详见 [硬件连接文档]hardware/hardware_documentation.md

### 软件编译
1. 打开Keil μVision，创建新项目（芯片选择AT89C52）
2. 添加 `firmware/main.c` 到项目
3. 取消注释所需功能宏定义
4. 编译并生成HEX文件
5. 使用STC-ISP下载到单片机

## 项目展示

### 系统整体布局
![系统整体图]https://private-user-images.githubusercontent.com/244897142/517736616-0aebe3cb-67fe-4815-8365-02f15cb7ebbe.jpg?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NjM4MjgwODMsIm5iZiI6MTc2MzgyNzc4MywicGF0aCI6Ii8yNDQ4OTcxNDIvNTE3NzM2NjE2LTBhZWJlM2NiLTY3ZmUtNDgxNS04MzY1LTAyZjE1Y2I3ZWJiZS5qcGc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUxMTIyJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MTEyMlQxNjA5NDNaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1hOTQyMTZiNTQ3MWRlNTg2NGFhZTY3ZWJkMzhlYWRiNTY0NjcxYjE1NmM3YzhiNWUxNzhhZTFmMGFkZDBlMTk2JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.ISwO-dwVT_R3rkm_Q-ZAXJ_B_MfLRUk2A31GlPEZTQM

### 硬件连接详情
![引脚分配图]https://private-user-images.githubusercontent.com/244897142/517736588-aaacc5ce-9ffa-4b83-907d-bce6637adf7d.jpg?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NjM4MjgwODMsIm5iZiI6MTc2MzgyNzc4MywicGF0aCI6Ii8yNDQ4OTcxNDIvNTE3NzM2NTg4LWFhYWNjNWNlLTlmZmEtNGI4My05MDdkLWJjZTY2MzdhZGY3ZC5qcGc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUxMTIyJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MTEyMlQxNjA5NDNaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT00MWE1MjczNDRhODlmNzZkYWIzMTNlYmFjZTMwODFiYmY5MjYxODI5YjRiNzk1YzFkZGM2YzcyOTY2MjdhZTUxJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.b4YW5HEud_gU1GGzagZsAubxPFDPY2p00xSNiRpxWv0

### 物料清单
![物料清单]https://private-user-images.githubusercontent.com/244897142/517736604-d6d55205-9617-4f02-b0ae-cfbb3a6f53c5.jpg?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NjM4MjgwODMsIm5iZiI6MTc2MzgyNzc4MywicGF0aCI6Ii8yNDQ4OTcxNDIvNTE3NzM2NjA0LWQ2ZDU1MjA1LTk2MTctNGYwMi1iMGFlLWNmYmIzYTZmNTNjNS5qcGc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUxMTIyJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MTEyMlQxNjA5NDNaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0zZjU4NTg2OTcwNzUwMmY2MTk4ZTZmMzU1NDM0ZDEzYzAxODczMmY0NjRiOTU5Mzg3YjJkYTZiYmRiOTgzNzcyJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.Ck--H2663b5Kv6q3kZQaDkvuPDRtChe4P1ykXOvljNI

## 🎮 使用说明

### 基本操作
1. **上电启动**：系统自动初始化，LED闪烁表示就绪
2. **计数功能**：按下按钮模拟物体通过，系统自动计数
3. **自动分拣**：每完成一个批次（默认5个），电机自动运行
4. **状态查看**：通过数码管实时查看计数状态

### 功能切换
通过修改代码中的宏定义切换工作模式：
```c
// 取消注释其中一个：
#define COMPLETE_SYSTEM         // 完整计数系统
// #define BASIC_LED_BLINK       // 基础LED闪烁
// #define DIGITAL_TUBE_TEST     // 数码管测试
// #define HARDWARE_TESTS        // 硬件测试
🔧技术亮点
资源优化
• 
引脚复用：P2口同时驱动两个数码管模块
• 
动态分配：32个I/O口实现复杂系统功能
• 
电源管理：电机独立供电，数字模拟分离
系统稳定性
• 
防抖动算法：可靠的按钮输入检测
• 
显示优化：无闪烁动态扫描
• 
错误处理：计数器溢出保护
学习价值
本项目涵盖了嵌入式开发的多个重要概念：
• 
GPIO控制与定时器使用
• 
数码管动态扫描原理
• 
电机驱动与PWM控制
• 
状态机设计与系统架构
• 
硬件调试与故障排查
🤝贡献指南
欢迎提交Issue和Pull Request来改进这个项目！