# Mandatory part

> 이 프로젝트는 엄격한 규칙들을 통해 가상머신(virtual machine)을 생성하고 구성하는 것을 다루고 있습니다. 피평가자는 동료평가 내내 당신을 도와줘야 합니다. 앞으로 나올 모든 평가 항목들이 직접 확인되어야한다는 점을 명심하세요.

<br>

## 1. 프로젝트 개요

*피평가자는 먼저 이것들을 간단히 설명해야합니다 :*

> 가상 머신은 어떻게 동작하는가.

	가상 머신은 Hypervisor위에서 동작한다. Hypervisor는 type1) 하드웨어 바로위에 Hypervisor가 설치되는 형태와 type2) 호스트 운영 체제 위에 Hypervisor가 설치되는 형태이고, 해당 프로젝트에서 사용하는 virtualbox역시 Type 2에 속한다. 여기서 호스트란 Hypervisor가 설치되는 물리적 하드웨어를 말한다. 게스트는 가상머신을 뜻한다.

> 어떤 운영시스템을 선택했는가

	Devian

> centOS와 Debian의 간단한 차이점들 (이 둘의 비교)

	centOS는 RedHat에서 개발한 유료 기업용 서버 OS인 RHEL에서 사후 기술지원과 상표권을 배제하고 제작한 오픈소스이다. 패키지 포맷으로 .rpm 확장자를 사용하고, yum을 패키지 관리 툴로 사용한다.

	Debian은 debian project에서 제작한 오픈소스이다. 패키지 포맷으로 .deb 확장자를 사용하고, dpkg와 APT를 패키지 관리 툴로 사용한다. 패키지 관리가 매우 쉬워 개인이 쓰기 적합하다.

> 가상머신의 목적 (가상머신을 쓰는 이유)

	1. 비용절감
	2. 간편함 + 속도
	3. downtime의 최소화

> ~~만약 피평가자가 CentOS를 선택했을 경우 : SeLinux와 DNF가 무엇인가~~

> 만약 피평가자가 Debian을 선택했을 경우 :<br>
> aptitude와 apt 사이의 차이점

	우선 공통점은 APT(Advanced Packaging Tool)로 필요한 패키지를 설치하는 툴로 둘다 CLI를 지원한다. 다만 aptitude는 GUI또한 제공하고 대화형으로 패키지를 검색해 설치, 제거할 수 있다. apt는 Low-level 패키지 매니저고 기존 apt-get이나 apt-cache등의 명령어들이 가지고있던 불필요한 옵션들은 제거하고 꼭 필요한 옵션들만 모았다.

> APPArmer이란 무엇인가

	debian 계열의 커널 레벨의 보안 모듈이다. enforce(허가되지 않은 파일에 접근하는 것을 거부) 모드와 complain(어플리케이션이 해야할 행동이 아닌 다른 행동을 하는경우에 로그를 남김) 모드가 있다.

	$ sudo aa-status

> - 디팬스 동안에 스크립트가 10분마다 정보를 출력해야한다 (이 동작은 나중에 평가 중에 더 자세히 체크하게 될 것입니다)

> - 만일 피평가자의 설명이 명확하지 않다면, 여기서 평가를 중단하십시오.

<br>

## 2. 기본 설정

명심하세요 : 만일 당신이 무언가를 체크하는데 도움이 필요하다면, 피평가자는 당신을 도울 수 있어야합니다.

>처음 실행할 때, 그래픽 환경이 아닌 지 확인 이 가상머신에 연결하고자 할 때, 비밀번호가 요구될 것입니다. 

>그리고 가상머신 연결 이후에는, 피평가자의 도움으로 사용자(user)에 연결해야 합니다.- 포트포워딩이 아니라 자기꺼로 들어가는것. 이때 이 사용자는 root가 아니여아합니다.

	포트포워딩 : 게이트웨이(외부망)의 반대쪽에 위치한 보호/내부망에 상주하는 호스트에 대한 서비스를 생성하기 위해 흔히 사용되며, 통신하는 목적지 IP 주소와 포트 번호를 내부 호스트에 다시 매핑 - 위키백과

>또, 이용하고 있는 비밀번호를 유심히 살펴보세요. 그 비밀번호는 이 과제에 주어진 규칙들을 따라야만합니다.

	길이 10자 이상, 대문자, 숫자 포함, 같은 문자 최대 3번

>UFW 서비스가 시작되었는지(실행되었는지) 평가자의 도움으로 확인하기
	
	$ sudo ufw status
	
>SSH 서비스가 시작되었는지 (평가자의 도움으로) 확인하기

	$ systemctl status ssh

>사용되는 OS가 Debian인지 CentOS인지 (평가자의 도움으로) 확인하기

	$ cat /etc/os-release

>만일 무언가가 예상한대로 작동하지 않거나 혹은 명확하게 설명되지 못한다면, 여기서 평가를 중단하십시오.

<br>

## 3. 사용자

명심하세요 : 만일 당신이 무언가를 체크하는데 도움이 필요하다면, 피평가자는 당신을 도울 수 있어야합니다.

>이 과제에서는, 피평가자가 로그인한 유저가 가상머신 속에 존재할 것을 요구합니다. 유저가 추가되었는지, 그리고 그것이 "sudo"와 "user42" 그룹에 속하는 지 살펴보세요.

	$ groups

이 과제에는 비밀번호 정책에 관해 제시된 규칙들이 있습니다. 이 규칙들이 제대로 설정되었는지 다음 절차를 따라 확인해보세요.

>먼저, 새로운 유저를 생성합니다. 과제에 제시된 규칙에 맞춰 임의로 그 비밀번호를 만듭니다.

	$ sudo adduser <NEW_USER>

>이제 피평가자는 어떻게 자신들이 과제에 제시된 규칙들을 설정했는지 설명해야합니다. 보통 1개 혹은 2개의 수정된 파일들이 있어야 합니다.

	$ sudo vi /etc/login.defs
	
	PASS_MAX_DAYS 30 // 30일 후 만료
	PASS_MIN_DAYS 2  // 최소 사용기간 2일
	PASS_WARN_AGE 7  // 7일전에 경고 보내기
	PASS_MIN_LEN 10  // 최소 10글자 이상

	$ sudo vi /etc/pam.d/common-password // 이 파일에서 비밀번호 정책 수정

	retry=3 // 암호 재입력은 최대 3회까지
	minlen=10 // 최소 길이 10
	difok=7 // 기존 패스워드와 달라야 하는 문자 수 7
	maxrepeat=3 // 동일한 문자를 반복 가능한 최대 횟수 3
	ucredit=-1 // 대문자 한개 이상 포함
	lcredit=-1 // 소문자 한개 이상 포함
	dcredit=-1 // 숫자 한개 이상 포함
	reject_username // username이 그대로 혹은 reversed 된 문자는 패스워드로 사용 불가
	enforce_for_root // root 계정도 위의 정책들 적용 

>만일 어떤 문제라도 생긴다면, 여기서 평가를 중단하십시오.

<br>

>이제 당신의 새로운 유저가 추가된 상태에서, 피평가자가 "evaluating"이라는 그룹을 생성하도록 합니다.

	$ sudo groupadd evaluating

>그리고 그 그룹을 이 유저에게 할당하도록 합니다. 최종적으로, 이 유저가 정말 "evaluating" 그룹에 속하게 되었는 지 확인해보세요.

	$ sudo usermod -aG evaluating <NEW_USER>

>피평가자가 이러한 비밀번호 정책의 장점을 설명하도록 하세요. 그리고 그것의 구현에서의 장점과 단점도 설명할 수 있어야합니다. 물론 그걸 대답해야하는 건 이 과제가 그걸 요구하기 떄문입니다. 그건 중요하지 않습니다.

	비밀번호 정책이 복잡할수록 보안이 좋아지지만 사용자가 비밀번호를 잊어버릴 가능성이 높아진다.

>만일 무언가가 예상한대로 작동하지 않거나 혹은 명확하게 설명되지 못한다면, 여기서 평가를 중단하십시오.

<br>

## 4. 호스트명과 파티션들

명심하세요 : 만일 당신이 무언가를 체크하는데 도움이 필요하다면, 피평가자는 당신을 도울 수 있어야합니다.

>이 가상머신의 호스트명이 다음의 주어진 형식을 만족하는 지 체크하세요 : login42 (피평가자의 로그인)

	$ hostnamectl

>당신의 로그인으로 대체해서 원래의 호스트명을 수정하세요. 그리고 가상머신을 다시 시작하세요. 만일 다시 시작했을 때, 호스트명이 업데이트 되어있지 않다면, 여기서 평가를 중단하십시오.

	$ sudo hostnamectl set-hostname <HOST_NAME>
	$ sudo reboot

>이제 가상머신을 다시 원래의 호스트명으로 복원할 수 있습니다.

<br>

>피평가자에게 어떻게 이 가상머신의 파티션들을 확인할 수 있는 지 물어보세요. 과제에 주어진 예시와 출력 결과물을 비교하십시오

	$ lsblk


>~~유의하세요 : 피평가자가 보너스 파트를 했다면, 꼭 보너스 예시에 대한 것도 확인해야합니다. 이 파트는 점수를 의논하기 위한 기회입니다.~~

>피평가자는 당신에게 어떻게 LVM이 동작하는지와 그게 대체 무엇인지에 대해 간단히 설명해야합니다

	LVM은 물리적인 디스크를 논리적인 디스크로 할당하여 유연하게 관리할 수 있게 해준다. 여러개의 하드 디스크 공간을 합쳐서 하나의 디스크처럼 사용할 수 있고 기존에 사용중인 디스크의 공간을 자유롭게 확장할 수 있다.

>만일 무언가가 예상한대로 작동하지 않거나 혹은 명확하게 설명되지 못한다면, 여기서 평가를 중단하십시오.

<br>

## 5. SUDO

명심하세요 : 만일 당신이 무언가를 체크하는데 도움이 필요하다면, 피평가자는 당신을 도울 수 있어야합니다.

>"sudo" 프로그램이 가상머신에 제대로 설치되어있는지 체크하세요.
이제 피평가자는 당신의 새로운 유저를 "sudo" 그룹에 할당하는 것을 보여줘야합니다.

	$ sudo --version
	$ sudo usermod -aG sudo <NEW_USER>

>이 과제는 sudo에 대한 엄격한 규칙들을 강요합니다. 피평가자는 여러 예시를 통해 sudo의 가치(사용하는 이유)와 동작을 보여줘야합니다.

	- 시스템 침입자가 sudo를 사용 하면 sudoers에 자신이 노출되기에 침입을 확인할 수 있다
	- root 계정에 장시간 머무를 일이 없어져서 위험한 command를 실행할 가능성이 낮아진다.
	- root의 password를 타인과 공유하지 않아도 된다.

>그 다음 단계에서는, 과제에서 강조하는 규칙들에 대한 구현을 보여주어야합니다.

	$ sudo visudo

	Defaults        secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
	// 보안을 위해 secure_path(sudo가 사용할 수 있는 경로)를 제한하라 (/A:/B ⇒ A에 없으면 B에서 찾아라)
	Defaults        passwd_tries=3
	// 일치하지 않는 password인 경우 입력은 3회로 제한하라
	Defaults        authfail_message="Authentication fal!"
	// Authentication 획득 실패 시 출력되는 error 메시지
	Defaults        badpass_message="wrong Password!"
	// password가 일치하지 않는 경우 출력되는 error 메시지
	Defaults        iolog_dir="/var/log/sudo"
	// log를 해당 디렉토리에 저장하라
	Defaults        log_input
	// sudo 명령어 실행 시 입력된 명령어를 iolog_dir에 log로 저장하라
	Defaults        log_output
	// sudo 명령어 실행 시 출력 결과를 iolog_dir에 log로 저장하라
	Defaults        requiretty
	// sudo 명령어가 tty모드에서만 실행되도록

>"/var/log/sudo/" 폴더가 존재하는 지, 그리고 그것이 최소한 한 개의 파일을 갖는 지 확인하세요.

	$ sudo ls /var/log/sudo

>이 폴더 속 파일들의 내용을 확인할 때, sudo와 함께 사용된 명령어들의 기록을 볼 수 있어야합니다.

>최종적으로, sudo를 통해 명령어를 실행해보세요. 그리고 "/var/log/sudo/" 폴더 속 파일(들)이 업데이트되었는 지 확인합니다.

	$ sudo vi /var/log/sudo/00/00/~


>만일 무언가가 예상한대로 작동하지 않거나 혹은 명확하게 설명되지 못한다면, 여기서 평가를 중단하십시오.

<br>

## 6. UFW

명심하세요 : 만일 당신이 무언가를 체크하는데 도움이 필요하다면, 피평가자는 당신을 도울 수 있어야합니다.

>"UFW" 프로그램이 가상머신에 제대로 설치되어있는 지 체크하세요.
그것이 제대로 동작하는 지 체크하세요

	UFW는 Uncomplicated Firewall의 약자로 복잡하지 않은 방화벽 관리 프로그램이다.

	$ sudo ufw --version
	$ sudo ufw status

>피평가자는 기본적으로 UFW가 무엇인지, 그리고 그걸 사용했을 때의 가치(좋은 점)을 설명할 수 있어야만 합니다.

	Linux 커널은 서버에 대한 client의 네트워크 접속을 제어하는 netfilter Module을 가지고 있다. 이것을 이용하여 서버 접속에 대한 network policy를 세우는 프로그램이 바로 Firewall(방화벽)이다. 이 방화벽 설정을 간편화 해주는 소프트웨어가 바로 UFW(Uncomplicated FireWall)이다. 해당 subject에는 port 22를 닫고 port 4242를 여는데 사용했다.

>UFW의 활성된 규칙들을 나열하세요. 4242 포트에 대한 규칙도 있어야만합니다.

	$ sudo cat /etc/ufw/user.rules

>8080 포트를 열기 위한 새로운 규칙을 추가하세요. 그리고 이것이 활성된 규칙의 목록에 추가되었는 지 체크하세요.

	$ sudo ufw allow 8080
	$ sudo cat /etc/ufw/user.rules

>최종적으로, 피평가자가 그 새로운 규칙을 삭제하도록 하세요.

	$ sudo ufw status numbered
	$ sudo ufw delete <NUMBER>

>만일 무언가가 예상한대로 작동하지 않거나 혹은 명확하게 설명되지 못한다면, 여기서 평가를 중단하십시오.

<br>

## 7. SSH

명심하세요 : 만일 당신이 무언가를 체크하는데 도움이 필요하다면, 피평가자는 당신을 도울 수 있어야합니다.

>SSH 서비스가 가상머신에 제대로 설치되어있는 지 체크하세요.
그것이 제대로 동작하는 지 체크하세요

	$ sudo ssh -V
	$ systemctl status ssh

>피평가자는 SSH가 무엇인지, 그리고 그걸 사용했을 때의 가치(좋은 점)을 설명할 수 있어야만 합니다.

	SSH는 원격으로 호스트(Shell)에 접속하기 위해 사용되는 보안 프로토콜이다. 즉, 모든 데이터는 암호화가 보장된다. private key는 클라이언트, public key는 호스트가 가지게 되어 이 한 쌍의 key를 이용하여 데이터를 암호화/복호화한다.

>SSH 서비스가 4242 포트만을 사용하는 지 확인하세요.

	$ sudo vi /etc/ssh/sshd_config

>피평가자는 당신이 새롭게 생성된 유저에 로그인하기 위해 SSH를 사용하는 것을 도와야합니다. 그렇게 하기 위해서는, 당신은 key나 간단한 비밀번호를 사용할 수 있습니다. 그건 피평가자에 따라 달라질 수 있습니다. 물론, 과제에 제시되었듯이, "root" 유저로 SSH를 사용할 수 없음을 확실히 확인해야합니다.

	$ ssh <NEW_USER>@<MAC_IP> -p 4242
	$ cat /etc/ssh/sshd_config | grep "PermitRootLogin"

>만일 무언가가 예상한대로 작동하지 않거나 혹은 명확하게 설명되지 못한다면, 여기서 평가를 중단하십시오.

<br>

## 8. Script monitoring

명심하세요 : 만일 당신이 무언가를 체크하는데 도움이 필요하다면, 피평가자는 당신을 도울 수 있어야합니다.

피평가자는 당신에게 다음의 내용들을 간단히 설명해야합니다 :

>스크립트가 어떻게 동작하는 지 당신에게 코드를 보여주기

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

>"cron"이란 무엇인지

	특정 작업을 특정 시간에 자동으로 실행시키기 위한 데몬이다. 또한 cron은 crontab 이라는 설정 파일을 기반으로 작동한다.

>피평가자가 어떻게 스크립트를 설정했길래 그게 (서버가 시작된 이후로) 10분마다 한번씩 실행되는지

	* * * * * command 
	| | | | |_ // 요일
	| | | |_ // 월
	| | |_ // 날짜
	| |_ // 시간
	|_ // 분

	// 10분마다 monitoring.sh를 싱행
	*/10 * * * * /monitoring.sh | wall

>일단 스크립트가 올바른 동작을 한다는 게 검증되고 나서는, 피평가자는 그 스크립트가 매분마다 실행되도록 해야합니다. 그 스크립트가 동적인 값들과 함께 올바르게 작동한다는 것을 보장하기 위해서, 당신은 원하는 무엇이든 실행시킬 수 있습니다.

	$ sudo crontab -e

	// crontab
	*/1 * * * * bash ~/monitoring.sh | wall

	$ sudo service cron restart

>최종적으로, 피평가자는 그 스크립트가 스스로를 수정하지 않고도 서버가 시작되면 실행을 멈추게끔 만들어야합니다. 이 점을 확인하기 위해서는, 당신은 마지막으로 한번 서버를 재시작해야 할 것 입니다.

	$ sudo systemctl disable cron
	$ sudo reboot

>막 시작되었을 때, 그 스크립트가 아직 같은 장소에 존재하는 지, 권리(권한)가 바뀌지 않은 채로 남아있는지, 그리고 수정되지 않았는 지 반드시 확인해야합니다.

	$ sudo service cron status
	$ sudo systemctl enable cron // enable 상태로 수정

>만일 무언가가 예상한대로 작동하지 않거나 혹은 명확하게 설명되지 못한다면, 여기서 평가를 중단하십시오.