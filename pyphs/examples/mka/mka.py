#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Sat Jan 14 11:50:23 2017

@author: Falaize
"""

from __future__ import absolute_import, division, print_function

import os
from pyphs import PHSNetlist, PHSGraph, PHSSimulation, signalgenerator
import numpy as np


label = 'mka'
path = os.path.realpath(__file__)[:os.path.realpath(__file__).rfind(os.sep)]
netlist_filename = path + os.sep + label + '.net'
netlist = PHSNetlist(netlist_filename)
graph = PHSGraph(netlist=netlist)
core = graph.buildCore()

if __name__ == '__main__':
    tsig = 0.01
    fs = 48000.

    config = {'fs': 48e3,
              'progressbar': True,
              'split': True,
              }
    simu = PHSSimulation(core, config)

    sig = signalgenerator(which='sin', f0=500., A=200., tsig=tsig, fs=fs)

    def sequ():
        for u in sig():
            yield np.array([u, ])

    nt = int(fs*tsig)
    simu.init(sequ=sequ(), nt=nt)

    simu.process()

    simu.data.plot_powerbal()
