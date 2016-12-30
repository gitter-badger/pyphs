# -*- coding: utf-8 -*-
"""
Created on Tue Jun 28 13:47:58 2016

@author: Falaize
"""
from pyphs.misc.date import get_date
from pyphs import __version__


def str_preamble(label):

    licence_text = """/*
    Copyright or © or Copr. Project-Team S3 (Sound Signals and \
Systems) and
    Analysis/Synthesis team, Laboratory of Sciences and Technologies of Music \
and
    Sound (UMR 9912), IRCAM-CNRS-UPMC, 1 place Igor Stravinsky, F-75004 Paris
    * contributors : Antoine Falaize, Thomas Hélie,
    * corresponding contributor: antoine.falaize@ircam.fr
    * date: """ + get_date() + """

    This software (pypHs) is a computer program whose purpose is to generate \
C++
    code for the simulation of multiphysics system described by graph \
structures.
    It is composed of a library (pypHs.py) and a dictionnary (Dictionnary.py)

    This software is governed by the CeCILL-B license under French law and
    abiding by the rules of distribution of free software.  You can  use,
    modify and/ or redistribute the software under the terms of the CeCILL-B
    license as circulated by CEA, CNRS and INRIA at the following URL
    "http://www.cecill.info".

    As a counterpart to the access to the source code and  rights to copy,
    modify and redistribute granted by the license, users are provided only
    with a limited warranty  and the software's author,  the holder of the
    economic rights, and the successive licensors  have only  limited \
liability.

    In this respect, the user's attention is drawn to the risks associated
    with loading,  using,  modifying and/or developing or reproducing the
    software by the user in light of its specific status of free software,
    that may mean  that it is complicated to manipulate,  and  that  also
    therefore means  that it is reserved for developers  and  experienced
    professionals having in-depth computer knowledge. Users are therefore
    encouraged to load and test the software's suitability as regards their
    requirements in conditions enabling the security of their systems and/or
    data to be ensured and,  more generally, to use and operate it in the
    same conditions as regards security.

    The fact that you are presently reading this means that you have had
    knowledge of the CeCILL-B license and that you accept its terms.

    Created on """ + get_date() + """

    @author: Antoine Falaize



===============================================================================

    This file was automatically generated \n    by PyPHS v""" + \
        str(__version__) + """, on """ + get_date() + """.

    It contains the code for the simulation of system '""" + \
        label.upper() + """'.

===============================================================================
*/
"""
    return licence_text
