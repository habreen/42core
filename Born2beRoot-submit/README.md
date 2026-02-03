*This project has been created as part of the 42 curriculum by hshamudh.*

# Born2beRoot

## Description

Born2beRoot is a system administration project focused on virtualization, Linux system configuration, and security best practices.  
The objective is to set up a secure virtual machine using a minimal Linux distribution while respecting strict rules regarding users, permissions, services, and security policies.

This project introduces:
- Linux installation and configuration
- User and group management
- Security hardening
- Firewall and SSH configuration
- Automation using cron

### Operating System Choice

For this project, **Debian** was chosen.

**Reasons for choosing Debian:**
- Stability and reliability
- Lightweight and suitable for servers
- Large community and documentation
- Uses AppArmor by default, which is easier to configure than SELinux

#### Debian vs Rocky Linux

| Debian | Rocky Linux |
|------|-------------|
| Community-driven | Enterprise-focused |
| Lightweight | Heavier |
| AppArmor | SELinux |
| Beginner-friendly | More complex |

### AppArmor vs SELinux

| AppArmor | SELinux |
|---------|---------|
| Profile-based | Label-based |
| Easier to configure | More powerful but complex |
| Debian default | Rocky default |

### UFW vs firewalld

| UFW | firewalld |
|----|-----------|
| Simple | Advanced |
| Easy to manage | Dynamic rules |
| Debian default | RHEL-based |

### VirtualBox vs UTM

| VirtualBox | UTM |
|-----------|-----|
| Cross-platform | macOS-focused |
| Widely supported | Less common |
| Used at 42 | Apple Silicon oriented |

### Design Choices

- **Partitioning**: LVM with separate partitions (`/`, `/home`, `/var`, `/tmp`, `/srv`, `/var/log`)
- **Security**:
  - Strong password policy
  - Sudo logging and restrictions
  - Firewall enabled
- **User Management**:
  - Dedicated user
  - No root SSH login
- **Services Installed**:
  - SSH
  - UFW
  - AppArmor
  - Cron

---

## Instructions

### System Information

```bash commands

uname -a
➡ Displays kernel version and system architecture.
cat /etc/os-release
➡ Confirms the operating system is Debian.
sudo adduser hshamudh
➡ Creates a new non-root user with a home directory.
sudo groupadd user42
➡ Creates the mandatory group required by the subject.
sudo usermod -aG user42,sudo hshamudh
➡ Adds the user to user42 and sudo groups.
groups hshamudh
➡ Confirms the user belongs to the correct groups.
sudo apt update && sudo apt install sudo
➡ Installs sudo for privilege escalation.
sudo visudo
Defaults        passwd_tries=3
Defaults        badpass_message="Wrong password!"
Defaults        logfile="/var/log/sudo/sudo.log"
Defaults        log_input,log_output
Defaults        requiretty
➡ Limits sudo attempts, logs all activity, and improves security.
sudo nano /etc/pam.d/common-password
password requisite pam_pwquality.so retry=3 minlen=10 ucredit=-1 lcredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root
➡ Enforces strong passwords (length, complexity, reuse prevention).
sudo nano /etc/login.defs
PASS_MAX_DAYS   30
PASS_MIN_DAYS   2
PASS_WARN_AGE   7
➡ Forces regular password changes.
sudo apt install openssh-server
➡ Enables remote access to the VM.
sudo nano /etc/ssh/sshd_config
Port 4242
PermitRootLogin no
➡ Changes default port and disables root login.
sudo systemctl restart ssh
sudo systemctl status ssh
➡ Applies and verifies configuration.
sudo apt install ufw
➡ Installs firewall.
sudo ufw allow 4242
➡ Allows SSH port.
sudo ufw enable
➡ Activates firewall rules.
sudo ufw status
➡ Verifies firewall is active.
sudo aa-status
➡ Confirms AppArmor is enabled and enforcing profiles.
sudo crontab -u root -e
*/10 * * * * /usr/local/bin/monitoring.sh
➡ Runs the monitoring script every 10 minutes.
for monitoring.sh create nano monitoring.sh 
add the script:
#!/bin/bash

# ARCH
arch=$(uname -a)

# CPU PHYSICAL
cpuf=$(grep "physical id" /proc/cpuinfo | wc -l)

# CPU VIRTUAL
cpuv=$(grep "processor" /proc/cpuinfo | wc -l)

# RAM
ram_total=$(free --mega | awk '$1 == "Mem:" {print $2}')
ram_use=$(free --mega | awk '$1 == "Mem:" {print $3}')
ram_percent=$(free --mega | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')

# DISK
disk_total=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} END {printf ("%.1fGb\n"), disk_t/1024}')
disk_use=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {print disk_u}')
disk_percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} {disk_t+= $2} END {printf("%d"), disk_u/disk_t*100}')

# CPU LOAD
cpul=$(vmstat 1 2 | tail -1 | awk '{printf $15}')
cpu_op=$(expr 100 - $cpul)
cpu_fin=$(printf "%.1f" $cpu_op)

# LAST BOOT
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')

# LVM USE
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

# TCP CONNEXIONS
tcpc=$(ss -ta | grep ESTAB | wc -l)

# USER LOG
ulog=$(users | wc -w)

# NETWORK
ip=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')

# SUDO
cmnd=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "	Architecture: $arch
	CPU physical: $cpuf
	vCPU: $cpuv
	Memory Usage: $ram_use/${ram_total}MB ($ram_percent%)
	Disk Usage: $disk_use/${disk_total} ($disk_percent%)
	CPU load: $cpu_fin%
	Last boot: $lb
	LVM use: $lvmu
	Connections TCP: $tcpc ESTABLISHED
	User log: $ulog
	Network: IP $ip ($mac)
	Sudo: $cmnd cmd"
uname -a to get CPU architecture
grep "physical id" /proc/cpuinfo | wc -l to get number of physical cores
grep processor /proc/cpuinfo | wc -l to get number of virtual cores
free --mega | awk '$1 == "Mem:" {print $3}' to get number mb of used memoir

free --mega | awk '$1 == "Mem:" {print $2}' to get number of total mb memoire

free --mega | awk '$1 == "Mem:" {printf("(%.2f%%)\n", $3/$2*100)}' to get percent of used memory
df -m | grep "/dev/" | grep -v "/boot" | awk '{use += $3} {total += $2} END {printf("(%d%%)\n"), use/total*100}' to get number of occuped disk memory
vmstat 1 4 | tail -1 | awk '{print $15}' to get cpu usage.
who -b | awk '$1 == "system" {print $3 " " $4}' to get date and time of last reboot.
if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi to know if LVM is active or not.
ss -ta | grep ESTAB | wc -l to get number of tcp connections
users | wc -w to get number of users
ip link | grep "link/ether" | awk '{print $2}' to get addressemac
journalctl _COMM=sudo | grep COMMAND | wc -l to get number of executed command
wall to display to user

