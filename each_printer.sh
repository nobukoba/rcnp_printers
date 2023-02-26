#!/bin/bash

printer_name=$1
if [ "" = "$printer_name" ]; then
    echo "Usage: ./each_printer.sh printer_name"
    echo "Example: ./each_printer.sh acc4150"
    exit
fi
echo $printer_name

snmpget=$HOME/prg/net-snmp-5.9.3/bin/snmpget

cur_time=`date '+%s %Y/%m/%d_%H:%M:%S'`

tnr_b_max=`$snmpget -v 2c -c public $printer_name mib-2.43.11.1.1.8.1.1 | cut -d' ' -f4`
tnr_y_max=`$snmpget -v 2c -c public $printer_name mib-2.43.11.1.1.8.1.2 | cut -d' ' -f4`
tnr_m_max=`$snmpget -v 2c -c public $printer_name mib-2.43.11.1.1.8.1.3 | cut -d' ' -f4`
tnr_c_max=`$snmpget -v 2c -c public $printer_name mib-2.43.11.1.1.8.1.4 | cut -d' ' -f4`
drm_b_max=`$snmpget -v 2c -c public $printer_name mib-2.43.11.1.1.8.1.6 | cut -d' ' -f4`
drm_y_max=`$snmpget -v 2c -c public $printer_name mib-2.43.11.1.1.8.1.7 | cut -d' ' -f4`
drm_m_max=`$snmpget -v 2c -c public $printer_name mib-2.43.11.1.1.8.1.8 | cut -d' ' -f4`
drm_c_max=`$snmpget -v 2c -c public $printer_name mib-2.43.11.1.1.8.1.9 | cut -d' ' -f4`
tnr_b_cur=`$snmpget -v 2c -c public $printer_name mib-2.43.11.1.1.9.1.1 | cut -d' ' -f4`
tnr_y_cur=`$snmpget -v 2c -c public $printer_name mib-2.43.11.1.1.9.1.2 | cut -d' ' -f4`
tnr_m_cur=`$snmpget -v 2c -c public $printer_name mib-2.43.11.1.1.9.1.3 | cut -d' ' -f4`
tnr_c_cur=`$snmpget -v 2c -c public $printer_name mib-2.43.11.1.1.9.1.4 | cut -d' ' -f4`
drm_b_cur=`$snmpget -v 2c -c public $printer_name mib-2.43.11.1.1.9.1.6 | cut -d' ' -f4`
drm_y_cur=`$snmpget -v 2c -c public $printer_name mib-2.43.11.1.1.9.1.7 | cut -d' ' -f4`
drm_m_cur=`$snmpget -v 2c -c public $printer_name mib-2.43.11.1.1.9.1.8 | cut -d' ' -f4`
drm_c_cur=`$snmpget -v 2c -c public $printer_name mib-2.43.11.1.1.9.1.9 | cut -d' ' -f4`
tnr_b_per=$(($tnr_b_cur*100/$tnr_b_max))
tnr_y_per=$(($tnr_y_cur*100/$tnr_y_max))
tnr_m_per=$(($tnr_m_cur*100/$tnr_m_max))
tnr_c_per=$(($tnr_c_cur*100/$tnr_c_max))
drm_b_per=$(($drm_b_cur*100/$drm_b_max))
drm_y_per=$(($drm_y_cur*100/$drm_y_max))
drm_m_per=$(($drm_m_cur*100/$drm_m_max))
drm_c_per=$(($drm_c_cur*100/$drm_c_max))


if [ "$printer_name" = "acc4150" ] || [ "$printer_name" = "rbc4150" ]; then
    btl___cur=`$snmpget -v 2c -c public $printer_name .1.3.6.1.4.1.253.8.53.13.2.1.6.1.207.5 | cut -d' ' -f4`
    if [ "$btl___cur" = "0"  ]; then
	btl___per=100
    elif [ "$btl___cur" = "1"  ]; then
	btl___per=0
    fi
else
    btl___max=`$snmpget -v 2c -c public $printer_name mib-2.43.11.1.1.8.1.5 | cut -d' ' -f4`
    btl___cur=`$snmpget -v 2c -c public $printer_name mib-2.43.11.1.1.9.1.5 | cut -d' ' -f4`
    if [ "$btl___cur" = "-3"  ]; then
	btl___per=100
    elif [ "$btl___cur" = "-2"  ]; then
	btl___per=0
    elif [ "$btl___cur" = "-1"  ]; then
	btl___per=0
    else
	btl___per=$(($btl___cur*100/$btl___max))
    fi
fi


echo $cur_time $tnr_b_per $tnr_c_per $tnr_m_per $tnr_y_per
echo $cur_time $drm_b_per $drm_c_per $drm_m_per $drm_y_per
echo $cur_time $btl___cur 
echo $cur_time $btl___per
echo $cur_time $tnr_b_per $tnr_c_per $tnr_m_per $tnr_y_per >> status/tnr_per_${printer_name}.txt
echo $cur_time $drm_b_per $drm_c_per $drm_m_per $drm_y_per >> status/drm_per_${printer_name}.txt
echo $cur_time $btl___cur                                  >> status/btl_${printer_name}.txt
echo $cur_time $btl___per                                  >> status/btl_per_${printer_name}.txt
