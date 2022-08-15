#!bin/bash
ARCH=$(uname -a)
PCPU=$(nproc --all)
VCPU=$(grep 'processor' /proc/cpuinfo | uniq | wc -l)
RAM=$(free -m | grep Mem: | awk '{printf" %d/%dMB (%.2f%%)\n", $3 , $2, $3 / $2 * 100'})
USEDDISK=$(df -BM | grep /dev/map | awk '{used += $3} END {printf "%d", used}')
FULLDISK=$(df -BM | grep /dev/map | awk '{full += $2} END {printf "%d", full}')
DISKRATE=$(df -BM | grep /dev/map | awk '{used += $3} {full += $2} END {printf("%d%%\n"), used / full * 100}')
CPULOAD=$(mpstat | grep all | awk '{printf "%.2f%%\n", 100-$13}')
LASTBOOT=$(who -b | awk '{print $3" "$4}')
LVM=$(if [ $(lsblk | grep lvm | wc -l) -eq 0 ]; then echo no; else echo yes; fi)
CONNECTION=$(cat /proc/net/sockstat | awk '$1 == "TCP:" {print $3 - 1 " ESTABLISHED"}')
USERS=$(who | wc -l)
IP=$(hostname -I)
MAC=$(ip addr | grep "ether " | awk '{print $2}' | sed -n '1p')
SUDO=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

echo "#Architecture: ${ARCH}"
echo "#CPU physical : ${PCPU}"
echo "#vCPU : ${VCPU}"
echo "#Memory Usage:${RAM}"
echo "#Dis Usage: ${USEDDISK}/${FULLDISK}MB (${DISKRATE})"
echo "#CPU load: ${CPULOAD}"
echo "#Last boot: ${LASTBOOT}"
echo "#LVM use: ${LVM}"
echo "#Connections TCP : ${CONNECTION}"
echo "#User log: ${USERS}"
echo "#Network: IP ${IP}(${MAC})"
echo "#Sudo : ${SUDO} cmd"
