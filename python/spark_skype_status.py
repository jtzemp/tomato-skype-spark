#!/usr/bin/env python

# curl https://api.spark.io/oauth/token -u spark:spark \
#      -d grant_type=password -d username=joe@example.com -d password=SuperSecretPasswordsAreCool

# curl -G https://api.spark.io/v1/devices/device-id -d access_token=secret-token
# curl https://api.spark.io/v1/devices/device-id/blinky -d access_token=secret-token -d args=5
# curl https://api.spark.io/v1/devices/device-id/tomato -d access_token=secret-token -d args=RED
# curl https://api.spark.io/v1/devices/device-id/tomato -d access_token=secret-token -d args=OFF

###### Using Skype4Py on a 64 bit machine ######
# virtualenv skype4py_virt_env
# lipo python -thin i386 -output python_i386
# lipo -info python
# lipo -info python_i386
# mv skype4py_virt_env/bin/python skype4py_virt_env/bin/python_universal
# ln -si python_i386 skype4py_virt_env/bin/python
# source skype4py_virt_env/bin/activate
# pip install Skype4py


access_token = 'secret-token'

import Skype4Py

skype = Skype4Py.Skype()
skype.Attach()

call_status = 0

def call_status_text(status):
    return skype.Convert.CallStatusToText(status)

def user_status(s):
    print 'User status: ' + s
    # if status is DND, make tomato red
    # if status is ONLINE, make tomato green
    # if status is AWAY, make tomato yellow
    # otherwise, turn tomato off

def call_handler(call, status):
    global CallStatus
    CallStatus = status
    print 'Call status: ' + call_status_text(status)
    # set status to DND if we're on a call
    # set status back to what it was when we're off


skype.OnUserStatus = printsomething
skype.OnCallStatus = OnCall
