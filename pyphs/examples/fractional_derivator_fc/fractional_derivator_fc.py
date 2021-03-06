#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat May 13 17:00:14 2017

@author: Falaize
"""

from __future__ import absolute_import, division, print_function

import os
from pyphs import (netlist2core, PHSSimulation, signalgenerator,
                   PHSNetlist, PHSGraph)
from pyphs.misc.signals.analysis import transferFunction
import matplotlib.pyplot as plt
import numpy as np

label = 'fractional_derivator_fc'

path = os.path.realpath(__file__)[:os.path.realpath(__file__).rfind(os.sep)]

netlist_filename = path + os.sep + label + '.net'
netlist = PHSNetlist(netlist_filename)
graph = PHSGraph(netlist=netlist)
core = netlist2core(netlist_filename)

if __name__ == '__main__':
    # UNCOMMENT BELOW FOR SIMULATION and PLOT OF TRANSFER FUNCTION
    # !!! Very long simulation with numpy

#    config = {'fs': 48e3,
#              'split': True,
#              'pbar': True,
#              'timer': True,
#              'lang': 'python'
#              }
#
#    simu = PHSSimulation(core, config=config)
#
#    dur = 10.
#    u = signalgenerator(which='noise', tsig=dur, fs=simu.fs)
#
#    def sequ():
#        for el in u():
#            yield (el, )
#
#    simu.init(sequ=sequ(), nt=int(dur*simu.fs))
#
#    simu.process()
#
#    u = list(simu.data.u(0))
#    y = list(simu.data.y(0))
#
#    f, TF = transferFunction(u, y, fs=simu.fs, nfft=2**13, limits=(1e2, 1e4))
#
#    plt.close('all')
#    plt.figure()
#    target = 5*np.abs((2*1j*np.pi*np.array(f))**0.5)
#    plt.loglog(f, target, '-r', label='target')
#    plt.loglog(f, TF, 'ob', label='simu')
#    plt.legend()
#    plt.xlabel('freq (Hz)')
#    plt.ylabel(r'$\mathrm{abs}(y(f)/u(f))$ ($\Omega$)')
#    plt.title('Transfer function')
    
    pass