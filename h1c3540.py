#!/usr/bin/python3

import urllib.request
import re
import os
import time
import datetime

printer_name = os.path.splitext(os.path.basename(__file__))[0]

url = 'http://'+printer_name+'/sttnr.htm'
response = urllib.request.urlopen(url)
content = response.read()
response.close()
charset = 'utf-8'
for line in content.splitlines():
    if (re.findall(b'<META.+Shift_JIS">',line)):
        charset = 'Shift_JIS'
content = content.decode(charset)
for line in content.splitlines():
    if (re.findall('var info=',line)):
        print(line)
        tnr_per = re.findall(',[0-9]+?,([0-9]+)',line)
        tnr = re.findall(',([0-9]+?),[0-9]+',line)

url = 'http://'+printer_name+'/stbot.htm'
response = urllib.request.urlopen(url)
content = response.read()
response.close()
content = content.decode(charset)
for line in content.splitlines():
    if (re.findall('var info=',line)):
        print(line)
        btl = re.findall('info=([0-9]+);',line)

url = 'http://'+printer_name+'/stdrm.htm'
response = urllib.request.urlopen(url)
content = response.read()
response.close()
content = content.decode(charset)
for line in content.splitlines():
    if (re.findall('var info=',line)):
        print(line)
        drm = re.findall(',([0-9]+)',line)
        
print(tnr_per)
print(tnr)
print(btl)
print(drm)
            
now = datetime.datetime.now()
utime = str(int(now.timestamp()))
dtime = now.strftime("%Y/%m/%d_%H:%M:%S")

ofile = open('./status/tnr_per_'+printer_name+'.txt','a')
ofile.write(utime+' '+dtime)
ofile.write(' '+tnr_per[3])
for i in range(0,3):
    ofile.write(' '+tnr_per[i])
ofile.write('\n')
ofile.close()

ofile = open('./status/tnr_'+printer_name+'.txt','a')
ofile.write(utime+' '+dtime)
ofile.write(' '+tnr[3])
for i in range(0,3):
    ofile.write(' '+tnr[i])
ofile.write('\n')
ofile.close()

ofile = open('./status/btl_'+printer_name+'.txt','a')
ofile.write(utime+' '+dtime)
ofile.write(' '+btl[0])
ofile.write('\n')
ofile.close()

ofile = open('./status/drm_'+printer_name+'.txt','a')
ofile.write(utime+' '+dtime)
ofile.write(' '+drm[3])
for i in range(0,3):
    ofile.write(' '+drm[i])
ofile.write('\n')
ofile.close()
