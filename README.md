# 🧠 Marlin 2.1.2.5 para Anet ET5

Firmware personalizado basado en **Marlin 2.1.2.5**, configurado y optimizado para la **Anet ET5** con placa original (STM32F407) y drivers **TMC2208 en modo Standalone**.

---

## ⚙️ Características principales

- ✅ Basado en la versión oficial **Marlin 2.1.2.5 desde davidtgbe 2.1 bugfix**
- 🖥️ Configurado para **Anet ET5 (placa Anet_ET4_ V1.x)**
- 🧩 Drivers **TMC2208_STANDALONE**
- 🔧 **Babystepping** activado para ajustar la altura Z durante la impresión
- 📏 Ajuste de **Z-Offset en tiempo real**
- 🧮 **EEPROM habilitada** (guardado de configuraciones con `M500`)
- ⚡ Compatible con **bootloader OpenBLT**
- 📡 Conexión por **USB o SD**
- 🌡️ Termistores configurados según stock de fábrica
- 🧱 Límites de movimiento, pasos por mm y volumen de impresión ajustados a valores originales de la ET5

---

## 🧭 Instrucciones de compilación

### 1. Requisitos
- [Visual Studio Code](https://code.visualstudio.com/)  
- Extensión [PlatformIO IDE](https://platformio.org/install/ide?install=vscode)

### 2. Clonar o descargar el repositorio
```bash
git clone https://github.com/santiis2010/Marlin-ET5Pro.git
```

### 3. Compilar
1. Abrí la carpeta del proyecto en **VSCode**.  
2. En `platformio.ini`, asegurate de usar el entorno:
   ```
   default_envs = Anet_ET4_OpenBLT
   ```
3. Compilá con el botón **Build** de PlatformIO (✔️).  
4. El archivo `.bin` generado estará en:  
   `.pio/build/Anet_ET4_OpenBLT/firmware.bin`

### 4. Cargar el firmware
- Copiá el `.bin` a una tarjeta SD.  
- Encendé la impresora y esperá a que el firmware se actualice automáticamente.  
- La pantalla se reiniciará sola una vez completado el proceso.

---

## 🧰 Funciones útiles (G-codes)

| Comando | Descripción |
|----------|--------------|
| `M500` | Guarda los valores en EEPROM |
| `M501` | Carga valores guardados |
| `M503` | Muestra la configuración actual |
| `M851` | Ajuste del Z-offset manual |
| `M851 Z-0.10` + `M500` | Guarda nuevo Z-offset |

---

## 🎛️ Babystepping en pantalla

Durante la impresión:
- Entrá en **Menú → Tune → Babystep Z**  
- Ajustá en pasos finos hasta obtener la primera capa perfecta.  
- El ajuste puede guardarse manualmente como nuevo `Z-offset`.

---

## 📦 Créditos

- Firmware base: [Marlin Firmware](https://github.com/MarlinFirmware/Marlin)  
- Adaptación y configuración: **Santiis2010 (2025)**  
- Comunidad de usuarios Anet ET5 Pro 🔧  

---

## 🪄 Licencia

Este firmware se distribuye bajo la licencia **GPLv3**, igual que el proyecto original de Marlin.

---

> 💬 *Si este firmware te resultó útil, considerá dejar una estrella ⭐ en el repositorio.*
