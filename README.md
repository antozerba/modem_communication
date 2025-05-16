# modem_communication
## 📋 Prerequisiti

Assicurati di aver configurato correttamente l'ambiente ROS 2 e di aver compilato il workspace.

Esegui:

Compilare il pachhetto:
```bash
colcon build
```

Attivare l'ambiente Ros2
```bash
source install/setup.bash
```

Far partire la simulazione DESERT:
```bash
ns uwApplicationTCP.tcl
```

Lanciare il node che pubblica sul topic e viene indirizzato dal mmiddlware rwm_desert

```bash
ros2 run modem_communication desert_publisher 
```
