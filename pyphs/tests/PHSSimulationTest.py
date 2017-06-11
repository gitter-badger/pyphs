#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Apr  2 05:40:20 2017

@author: Falaize
"""

# Support for Python 2.x and Python 3.x
from __future__ import division

# import of external packages
import numpy                     # numerical tools

# retrieve the pyphs.PHSCore of a nonlinear RLC from the tutorial on PHSCore
from pyphs.tutorials.phscore import core as nlcore

from pyphs.examples.rlc.rlc import core

from pyphs import PHSSimulation, signalgenerator

from pyphs.numerics.cpp.simu2cpp import simu2cpp
import os
import shutil


here = os.path.realpath(__file__)[:os.path.realpath(__file__).rfind(os.sep)]
path = os.path.join(here, 'simu')


def simulation_rlc_with_split():
    rlc = core.__deepcopy__()
    config = {'fs': 48e3,           # Sample rate
              'grad': 'discret',    # in {'discret', 'theta', 'trapez'}
              'theta': 0.5,         # theta-scheme for the structure
              'split': True,        # apply core.split_linear() beforehand
              'maxit': 10,          # Max iteration for NL solvers
              'eps': 1e-16,         # Global numerical tolerance
              'path': path,         # Path to the results folder
              'pbar': True,         # Display a progress bar
              'timer': True,        # Display minimal timing infos
              'lang': 'python',     # in {'python', 'c++'}
              'script': None,       # compile and exec binary
              'eigen': None,}       # path to Eigen library

    simu = PHSSimulation(rlc, config=config)

    dur = 0.01
    u = signalgenerator(which='sin', f0=800.,
                        tsig=dur, fs=simu.config['fs'])

    def sequ():
        for el in u():
            yield (el, )

    simu.init(u=sequ(), nt=int(dur*simu.config['fs']))
    simu.process()

    shutil.rmtree(path)
    return True


def simulation_rlc_cpp():
    rlc = core.__deepcopy__()
    # Define the simulation parameters
    config = {'fs': 48e3,               # Sample rate
              'grad': 'discret',    # in {'discret', 'theta', 'trapez'}
              'theta': 0.5,             # theta-scheme for the structure
              'split': True,           # apply core.split_linear() beforehand
              'maxit': 10,              # Max iteration for NL solvers
              'eps': 1e-16,          # Global numerical tolerance
              'path': path,             # Path to the results folder
              'pbar': False,      # Display a progress bar
              'timer': True,            # Display minimal timing infos
              'lang': 'c++',     # in {'python', 'c++'}
              }

    simu = PHSSimulation(rlc, config=config)

    dur = 0.01
    u = signalgenerator(which='sin', f0=800., tsig=dur, fs=simu.config['fs'])

    def sequ():
        for el in u():
            yield (el, )

    simu.init(u=sequ(), nt=int(dur*simu.config['fs']))
    simu2cpp(simu)

    shutil.rmtree(path)
    return True



def simulation_rlc_without_split():
    rlc = core.__deepcopy__()
    # Define the simulation parameters
    config = {'fs': 48e3,               # Sample rate
              'grad': 'discret',    # in {'discret', 'theta', 'trapez'}
              'theta': 0.5,             # theta-scheme for the structure
              'split': False,           # apply core.split_linear() beforehand
              'maxit': 10,              # Max iteration for NL solvers
              'eps': 1e-16,          # Global numerical tolerance
              'path': path,             # Path to the results folder
              'pbar': False,      # Display a progress bar
              'timer': True,            # Display minimal timing infos
              'lang': 'python',     # in {'python', 'c++'}
              'script': None,  # compile and exec binary
              'eigen': None,       # path to Eigen library
              }

    simu = PHSSimulation(rlc, config=config)

    dur = 0.01
    u = signalgenerator(which='sin', f0=800., tsig=dur, fs=simu.config['fs'])

    def sequ():
        for el in u():
            yield (el, )

    simu.init(u=sequ(), nt=int(dur*simu.config['fs']))

    simu.process()

    shutil.rmtree(path)
    return True


def simulation_rlc_without_split_trapez():
    rlc = core.__deepcopy__()
    # Define the simulation parameters
    config = {'fs': 48e3,               # Sample rate
              'grad': 'trapez',    # in {'discret', 'theta', 'trapez'}
              'theta': 0.5,             # theta-scheme for the structure
              'split': False,           # apply core.split_linear() beforehand
              'maxit': 10,              # Max iteration for NL solvers
              'eps': 1e-16,          # Global numerical tolerance
              'path': path,             # Path to the results folder
              'pbar': False,      # Display a progress bar
              'timer': True,            # Display minimal timing infos
              'lang': 'python',     # in {'python', 'c++'}
              'script': None,  # compile and exec binary
              'eigen': None,       # path to Eigen library
              }

    simu = PHSSimulation(rlc, config=config)

    dur = 0.01
    u = signalgenerator(which='sin', f0=800., tsig=dur, fs=simu.config['fs'])

    def sequ():
        for el in u():
            yield (el, )

    simu.init(u=sequ(), nt=int(dur*simu.config['fs']))

    simu.process()

    shutil.rmtree(path)
    return True


def simulation_rlc_without_split_theta():
    rlc = core.__deepcopy__()
    # Define the simulation parameters
    config = {'fs': 48e3,               # Sample rate
              'grad': 'theta',    # in {'discret', 'theta', 'trapez'}
              'theta': 0.5,             # theta-scheme for the structure
              'split': False,           # apply core.split_linear() beforehand
              'maxit': 10,              # Max iteration for NL solvers
              'eps': 1e-16,          # Global numerical tolerance
              'path': path,             # Path to the results folder
              'pbar': False,      # Display a progress bar
              'timer': True,            # Display minimal timing infos
              'lang': 'python',     # in {'python', 'c++'}
              'script': None,  # compile and exec binary
              'eigen': None,       # path to Eigen library
              }

    simu = PHSSimulation(rlc, config=config)

    dur = 0.01
    u = signalgenerator(which='sin', f0=800., tsig=dur, fs=simu.config['fs'])

    def sequ():
        for el in u():
            yield (el, )

    simu.init(u=sequ(), nt=int(dur*simu.config['fs']))

    simu.process()

    shutil.rmtree(path)
    return True


def simulation_rlc_plot():
    rlc = core.__deepcopy__()
    # Define the simulation parameters
    config = {'fs': 48e3,               # Sample rate
              'grad': 'discret',    # in {'discret', 'theta', 'trapez'}
              'theta': 0.5,             # theta-scheme for the structure
              'split': False,           # apply core.split_linear() beforehand
              'maxit': 10,              # Max iteration for NL solvers
              'eps': 1e-16,          # Global numerical tolerance
              'path': path,             # Path to the results folder
              'pbar': False,      # Display a progress bar
              'timer': True,            # Display minimal timing infos
              'lang': 'python',     # in {'python', 'c++'}
              'script': None,  # compile and exec binary
              'eigen': None,       # path to Eigen library
              }

    simu = PHSSimulation(rlc, config=config)

    dur = 0.01
    u = signalgenerator(which='sin', f0=800., tsig=dur, fs=simu.config['fs'])

    def sequ():
        for el in u():
            yield (el, )

    simu.init(u=sequ(), nt=int(dur*simu.config['fs']))

    simu.process()
    simu.data.plot_powerbal(mode='multi')

    shutil.rmtree(path)
    return True


def simulation_nlcore_full():

    # Define the simulation parameters
    config = {'fs': 48e3,               # Sample rate
              'grad': 'discret',    # in {'discret', 'theta', 'trapez'}
              'theta': 0.5,             # theta-scheme for the structure
              'split': False,           # apply core.split_linear() beforehand
              'maxit': 10,              # Max iteration for NL solvers
              'eps': 1e-16,          # Global numerical tolerance
              'path': path,             # Path to the results folder
              'pbar': False,      # Display a progress bar
              'timer': True,            # Display minimal timing infos
              'lang': 'python',     # in {'python', 'c++'}
              'script': None,  # compile and exec binary
              'eigen': None,       # path to Eigen library
              }


    # Instantiate a pyphs.PHSSimulation object associated with a given core PHS
    simu = PHSSimulation(nlcore, config=config)

    # def simulation time
    tmax = 0.02
    nmax = int(tmax*simu.config['fs'])
    t = [n/simu.config['fs'] for n in range(nmax)]
    nt = len(t)

    # def input signal
    def sig(tn, mode='impact'):
        freq = 1000.
        amp = 1000.
        if mode == 'sin':
            pi = numpy.pi
            sin = numpy.sin
            out = amp * sin(2*pi*freq*tn)
        elif mode == 'impact':
            dur = 0.5*1e-3  # duration: 0.5ms
            start = 0.001   # start at 1ms
            out = amp if start <= tn < start + dur else 0.
        elif mode == 'const':
            out = 1.
        return out

    # def generator for sequence of inputs to feed in the PHSSimulation object
    def sequ():
        """
        generator of input sequence for PHSSimulation
        """
        for tn in t:
            u1 = sig(tn)

            # !!! must be array with shape (core.dims.u(), )
            yield numpy.array([u1, ])  # numpy.array([u1, u2, ...])

    # state initialization
    # !!! must be array with shape (core.dims.x(), )
    x0 = (0., 0.)

    # Initialize the simulation
    simu.init(u=sequ(), x0=x0, nt=nt)

    # Proceed
    simu.process()

    shutil.rmtree(path)
    return True
