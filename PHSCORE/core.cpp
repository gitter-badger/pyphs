/*
    Copyright or (c) or Copr. Project-Team S3 (Sound Signals and Systems) and
    Analysis/Synthesis team, Laboratory of Sciences and Technologies of Music and
    Sound (UMR 9912), IRCAM-CNRS-UPMC, 1 place Igor Stravinsky, F-75004 Paris
    * contributors : Antoine Falaize, Thomas Helie,
    * corresponding contributor: antoine.falaize@ircam.fr
    * date: 2016/12/31 12:47:34

    This has been geerated by PyPHS which purpose is to generate C++
    code for the simulation of multiphysics system described by graph structures.

    This software is governed by the CeCILL-B license under French law and
    abiding by the rules of distribution of free software.  You can  use,
    modify and/ or redistribute the software under the terms of the CeCILL-B
    license as circulated by CEA, CNRS and INRIA at the following URL
    "http://www.cecill.info".

    As a counterpart to the access to the source code and  rights to copy,
    modify and redistribute granted by the license, users are provided only
    with a limited warranty  and the software's author,  the holder of the
    economic rights, and the successive licensors  have only  limited liability.

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

    Created on 2016/12/31 12:47:34

    author: Antoine Falaize


===========================================================================

    This file was automatically generated by PyPHS, date 2017/04/16 22:01:44.

    It contains the code for the simulation of system 'PHSCORE'.

===========================================================================
*/

#include "core.h"

// PUBLIC    
    
    void PHSCORE::update(vector<double> & u_vec, vector<double> & p_vec){
    
        set_u(u_vec);
        set_p(p_vec);
        
        ud_x_update();
        set_x(_ud_x);
        jacFll_update();
        jacFnll_update();
        ijacFll_update();
        Gl_update();
        Gnl_update();
        Fnl_update();
        res_Fnl_update();
        
        unsigned int iter_res_Fnl = 0;
        _step_Fnl = 1;
        while ((iter_res_Fnl<100) & (res_Fnl()>2.22044604925e-16) & (step_Fnl()>2.22044604925e-16)){    
            save_Fnl_update();
            jacGlnl_update();
            jacGnlnl_update();
            jacFnl_update();
            ijacFnl_update();
            ud_vnl_update();
            set_vnl(_ud_vnl);
            Gl_update();
            Gnl_update();
            Fnl_update();
            res_Fnl_update();
            step_Fnl_update();iter_res_Fnl += 1;
        }
        
        ud_vl_update();
        set_vl(_ud_vl);
        dxH_update();
        z_update();
        y_update();
    }
    
    // Acessors to Arguments, return vector<double>
    
    
    vector<double> PHSCORE::x_vector() const {    
        vector<double> v = vector<double>(2);    
        v[0] = *xL;    
        v[1] = *xC;    
        return v;
    }
    
    vector<double> PHSCORE::xl_vector() const {    
        vector<double> v = vector<double>(0);    
        return v;
    }
    
    vector<double> PHSCORE::xnl_vector() const {    
        vector<double> v = vector<double>(2);    
        v[0] = *xL;    
        v[1] = *xC;    
        return v;
    }
    
    vector<double> PHSCORE::dx_vector() const {    
        vector<double> v = vector<double>(2);    
        v[0] = *dxL;    
        v[1] = *dxC;    
        return v;
    }
    
    vector<double> PHSCORE::dxl_vector() const {    
        vector<double> v = vector<double>(0);    
        return v;
    }
    
    vector<double> PHSCORE::dxnl_vector() const {    
        vector<double> v = vector<double>(2);    
        v[0] = *dxL;    
        v[1] = *dxC;    
        return v;
    }
    
    vector<double> PHSCORE::w_vector() const {    
        vector<double> v = vector<double>(0);    
        return v;
    }
    
    vector<double> PHSCORE::wl_vector() const {    
        vector<double> v = vector<double>(0);    
        return v;
    }
    
    vector<double> PHSCORE::wnl_vector() const {    
        vector<double> v = vector<double>(0);    
        return v;
    }
    
    vector<double> PHSCORE::u_vector() const {    
        vector<double> v = vector<double>(1);    
        v[0] = *vout;    
        return v;
    }
    
    vector<double> PHSCORE::p_vector() const {    
        vector<double> v = vector<double>(0);    
        return v;
    }
    
    vector<double> PHSCORE::v_vector() const {    
        vector<double> v = vector<double>(2);    
        v[0] = *dxL;    
        v[1] = *dxC;    
        return v;
    }
    
    vector<double> PHSCORE::vl_vector() const {    
        vector<double> v = vector<double>(0);    
        return v;
    }
    
    vector<double> PHSCORE::vnl_vector() const {    
        vector<double> v = vector<double>(2);    
        v[0] = *dxL;    
        v[1] = *dxC;    
        return v;
    }
    
    // Acessors to Arguments, return Matrix<double, n, m>
    
    Matrix<double, 2, 1> PHSCORE::x() const {    
        Matrix<double, 2, 1> m;    
        m(0, 0) = *xL;    
        m(1, 0) = *xC;    
        return m;
    }
    Matrix<double, 0, 0> PHSCORE::xl() const {    
        Matrix<double, 0, 0> m;    
        return m;
    }
    Matrix<double, 2, 1> PHSCORE::xnl() const {    
        Matrix<double, 2, 1> m;    
        m(0, 0) = *xL;    
        m(1, 0) = *xC;    
        return m;
    }
    Matrix<double, 2, 1> PHSCORE::dx() const {    
        Matrix<double, 2, 1> m;    
        m(0, 0) = *dxL;    
        m(1, 0) = *dxC;    
        return m;
    }
    Matrix<double, 0, 0> PHSCORE::dxl() const {    
        Matrix<double, 0, 0> m;    
        return m;
    }
    Matrix<double, 2, 1> PHSCORE::dxnl() const {    
        Matrix<double, 2, 1> m;    
        m(0, 0) = *dxL;    
        m(1, 0) = *dxC;    
        return m;
    }
    Matrix<double, 0, 0> PHSCORE::w() const {    
        Matrix<double, 0, 0> m;    
        return m;
    }
    Matrix<double, 0, 0> PHSCORE::wl() const {    
        Matrix<double, 0, 0> m;    
        return m;
    }
    Matrix<double, 0, 0> PHSCORE::wnl() const {    
        Matrix<double, 0, 0> m;    
        return m;
    }
    Matrix<double, 1, 1> PHSCORE::u() const {    
        Matrix<double, 1, 1> m;    
        m(0, 0) = *vout;    
        return m;
    }
    Matrix<double, 0, 0> PHSCORE::p() const {    
        Matrix<double, 0, 0> m;    
        return m;
    }
    Matrix<double, 2, 1> PHSCORE::v() const {    
        Matrix<double, 2, 1> m;    
        m(0, 0) = *dxL;    
        m(1, 0) = *dxC;    
        return m;
    }
    Matrix<double, 0, 0> PHSCORE::vl() const {    
        Matrix<double, 0, 0> m;    
        return m;
    }
    Matrix<double, 2, 1> PHSCORE::vnl() const {    
        Matrix<double, 2, 1> m;    
        m(0, 0) = *dxL;    
        m(1, 0) = *dxC;    
        return m;
    }
    
    // Mutators for Arguments, type = vector<double>
    
    void PHSCORE::set_x(vector<double> & v) {
        *xL = v[0];
        *xC = v[1];
    }
    void PHSCORE::set_xl(vector<double> & v) {
    }
    void PHSCORE::set_xnl(vector<double> & v) {
        *xL = v[0];
        *xC = v[1];
    }
    void PHSCORE::set_dx(vector<double> & v) {
        *dxL = v[0];
        *dxC = v[1];
    }
    void PHSCORE::set_dxl(vector<double> & v) {
    }
    void PHSCORE::set_dxnl(vector<double> & v) {
        *dxL = v[0];
        *dxC = v[1];
    }
    void PHSCORE::set_w(vector<double> & v) {
    }
    void PHSCORE::set_wl(vector<double> & v) {
    }
    void PHSCORE::set_wnl(vector<double> & v) {
    }
    void PHSCORE::set_u(vector<double> & v) {
        *vout = v[0];
    }
    void PHSCORE::set_p(vector<double> & v) {
    }
    void PHSCORE::set_v(vector<double> & v) {
        *dxL = v[0];
        *dxC = v[1];
    }
    void PHSCORE::set_vl(vector<double> & v) {
    }
    void PHSCORE::set_vnl(vector<double> & v) {
        *dxL = v[0];
        *dxC = v[1];
    }
    
    // Mutators for Arguments, type = Matrix<double, n, m>
    
    void PHSCORE::set_x(Matrix<double, 2, 1> & m) {
        *xL = m(0, 0);
        *xC = m(1, 0);
    }
    void PHSCORE::set_xl(Matrix<double, 0, 0> & m) {
    }
    void PHSCORE::set_xnl(Matrix<double, 2, 1> & m) {
        *xL = m(0, 0);
        *xC = m(1, 0);
    }
    void PHSCORE::set_dx(Matrix<double, 2, 1> & m) {
        *dxL = m(0, 0);
        *dxC = m(1, 0);
    }
    void PHSCORE::set_dxl(Matrix<double, 0, 0> & m) {
    }
    void PHSCORE::set_dxnl(Matrix<double, 2, 1> & m) {
        *dxL = m(0, 0);
        *dxC = m(1, 0);
    }
    void PHSCORE::set_w(Matrix<double, 0, 0> & m) {
    }
    void PHSCORE::set_wl(Matrix<double, 0, 0> & m) {
    }
    void PHSCORE::set_wnl(Matrix<double, 0, 0> & m) {
    }
    void PHSCORE::set_u(Matrix<double, 1, 1> & m) {
        *vout = m(0, 0);
    }
    void PHSCORE::set_p(Matrix<double, 0, 0> & m) {
    }
    void PHSCORE::set_v(Matrix<double, 2, 1> & m) {
        *dxL = m(0, 0);
        *dxC = m(1, 0);
    }
    void PHSCORE::set_vl(Matrix<double, 0, 0> & m) {
    }
    void PHSCORE::set_vnl(Matrix<double, 2, 1> & m) {
        *dxL = m(0, 0);
        *dxC = m(1, 0);
    }
    
    // Functions Results Accessors
    
    Matrix<double, 0, 0> PHSCORE::jacFll() const {
        return _jacFll;
    }
    Matrix<double, 2, 0> PHSCORE::jacFnll() const {
        return _jacFnll;
    }
    Matrix<double, 0, 0> PHSCORE::Gl() const {
        return _Gl;
    }
    Matrix<double, 2, 1> PHSCORE::Gnl() const {
        return _Gnl;
    }
    Matrix<double, 0, 2> PHSCORE::jacGlnl() const {
        return _jacGlnl;
    }
    Matrix<double, 2, 2> PHSCORE::jacGnlnl() const {
        return _jacGnlnl;
    }
    Matrix<double, 2, 1> PHSCORE::dxH() const {
        return _dxH;
    }
    Matrix<double, 0, 0> PHSCORE::z() const {
        return _z;
    }
    Matrix<double, 1, 1> PHSCORE::y() const {
        return _y;
    }
    
    // Functions Results Accessors
    
    vector<double> PHSCORE::jacFll_vector() const {    
        vector<double> v = vector<double>(0);    
        return v;
    }
    vector<double> PHSCORE::jacFnll_vector() const {    
        vector<double> v = vector<double>(2);    
        v[0] = _jacFnll(0, 0);    
        v[1] = _jacFnll(1, 0);    
        return v;
    }
    vector<double> PHSCORE::Gl_vector() const {    
        vector<double> v = vector<double>(0);    
        return v;
    }
    vector<double> PHSCORE::Gnl_vector() const {    
        vector<double> v = vector<double>(2);    
        v[0] = _Gnl(0, 0);    
        v[1] = _Gnl(1, 0);    
        return v;
    }
    vector<double> PHSCORE::jacGlnl_vector() const {    
        vector<double> v = vector<double>(0);    
        return v;
    }
    vector<double> PHSCORE::jacGnlnl_vector() const {    
        vector<double> v = vector<double>(2);    
        v[0] = _jacGnlnl(0, 0);    
        v[1] = _jacGnlnl(1, 0);    
        return v;
    }
    vector<double> PHSCORE::dxH_vector() const {    
        vector<double> v = vector<double>(2);    
        v[0] = _dxH(0, 0);    
        v[1] = _dxH(1, 0);    
        return v;
    }
    vector<double> PHSCORE::z_vector() const {    
        vector<double> v = vector<double>(0);    
        return v;
    }
    vector<double> PHSCORE::y_vector() const {    
        vector<double> v = vector<double>(1);    
        v[0] = _y(0, 0);    
        return v;
    }
    
    // Oprations Results Accessors
    
    Matrix<double, 2, 1> PHSCORE::ud_x() const {
        return _ud_x;
    }
    Matrix<double, 0, 0> PHSCORE::ijacFll() const {
        return _ijacFll;
    }
    Matrix<double, 0, 0> PHSCORE::ud_vl() const {
        return _ud_vl;
    }
    Matrix<double, 2, 1> PHSCORE::save_Fnl() const {
        return _save_Fnl;
    }
    double PHSCORE::res_Fnl() const {
        return _res_Fnl;
    }
    Matrix<double, 2, 1> PHSCORE::Fnl() const {
        return _Fnl;
    }
    Matrix<double, 2, 2> PHSCORE::jacFnl() const {
        return _jacFnl;
    }
    Matrix<double, 2, 2> PHSCORE::ijacFnl() const {
        return _ijacFnl;
    }
    Matrix<double, 2, 1> PHSCORE::ud_vnl() const {
        return _ud_vnl;
    }
    double PHSCORE::step_Fnl() const {
        return _step_Fnl;
    }
    
    // Oprations Results Accessors
    
    vector<double> PHSCORE::ud_x_vector() const {    
        vector<double> v = vector<double>(2);    
        v[0] = _ud_x(0, 0);    
        v[1] = _ud_x(1, 0);    
        return v;
    }
    vector<double> PHSCORE::ijacFll_vector() const {    
        vector<double> v = vector<double>(0);    
        return v;
    }
    vector<double> PHSCORE::ud_vl_vector() const {    
        vector<double> v = vector<double>(0);    
        return v;
    }
    vector<double> PHSCORE::save_Fnl_vector() const {    
        vector<double> v = vector<double>(2);    
        v[0] = _save_Fnl(0, 0);    
        v[1] = _save_Fnl(1, 0);    
        return v;
    }
    vector<double> PHSCORE::Fnl_vector() const {    
        vector<double> v = vector<double>(2);    
        v[0] = _Fnl(0, 0);    
        v[1] = _Fnl(1, 0);    
        return v;
    }
    vector<double> PHSCORE::ud_vnl_vector() const {    
        vector<double> v = vector<double>(2);    
        v[0] = _ud_vnl(0, 0);    
        v[1] = _ud_vnl(1, 0);    
        return v;
    }
    
    // Default Constructor
    
    PHSCORE::PHSCORE(){
        init();
    };
    
    // Constructor with vector state initalization
    
    PHSCORE::PHSCORE(vector<double> & x0){
    
        if (x().size() == x0.size()) {
            set_x(x0);
        }
        else {
            cerr << "Size of x0 does not match size of x" << endl;
            exit(1);
        }
        init();
    };
    
    // Constructor with matrix state initalization
    
    PHSCORE::PHSCORE(Matrix<double, 2, 1> & x0){
    set_x(x0);
        init();
    };
    
    // Default Destructor
    
    PHSCORE::~PHSCORE(){
    };


// PRIVATE    
    
    // Functions Results Updates
    
    void PHSCORE::jacFll_update(){
    };
    void PHSCORE::jacFnll_update(){
    };
    void PHSCORE::Gl_update(){
    };
    void PHSCORE::Gnl_update(){
    _Gnl(0, 0) = 1.0*(25.0*pow((*dxL), 3) + 150.0*pow((*dxL), 2)*(*xL) + 300.0*(*dxL)*pow((*xL), 2) + 48100.0*(*dxL) + 1.0*(*vout) + 200.0*pow((*xL), 3) + 200.0*(*xL) + 1.0*(((*dxC) < -2.22044604925031e-16) ? (
       4934802200544.68*pow((*dxC), 3) + 19739208802178.7*pow((*dxC), 2)*(*xC) + 29608813203268.1*(*dxC)*pow((*xC), 2) + 98696.0440108936*(*dxC) + 19739208802178.7*pow((*xC), 3) + 197392.088021787*(*xC)
    )
    : (((*dxC) < 2.22044604925031e-16) ? (
       19739208802178.7*pow((*xC), 3) + 197392.088021787*(*xC)
    )
    : (
       4934802200544.68*pow((*dxC), 3) + 19739208802178.7*pow((*dxC), 2)*(*xC) + 29608813203268.1*(*dxC)*pow((*xC), 2) + 98696.0440108936*(*dxC) + 19739208802178.7*pow((*xC), 3) + 197392.088021787*(*xC)
    ))));
    _Gnl(1, 0) = -1.0*(-48000.0*(*dxC) + 1.0*(*dxL) + 2.0*(*xL) + 1.0*(((*dxC) < -2.22044604925031e-16) ? (
       4934802200544.68*pow((*dxC), 3) + 19739208802178.7*pow((*dxC), 2)*(*xC) + 29608813203268.1*(*dxC)*pow((*xC), 2) + 98696.0440108936*(*dxC) + 19739208802178.7*pow((*xC), 3) + 197392.088021787*(*xC)
    )
    : (((*dxC) < 2.22044604925031e-16) ? (
       19739208802178.7*pow((*xC), 3) + 197392.088021787*(*xC)
    )
    : (
       4934802200544.68*pow((*dxC), 3) + 19739208802178.7*pow((*dxC), 2)*(*xC) + 29608813203268.1*(*dxC)*pow((*xC), 2) + 98696.0440108936*(*dxC) + 19739208802178.7*pow((*xC), 3) + 197392.088021787*(*xC)
    )))*(((*dxC) < -2.22044604925031e-16) ? (
       24674011002723.4*pow((*dxC), 3) + 64152428607080.8*pow((*dxC), 2)*(*xC) + 59217626406536.2*(*dxC)*pow((*xC), 2) + 197392.088021787*(*dxC) + 19739208802178.7*pow((*xC), 3) + 197392.088021787*(*xC)
    )
    : (((*dxC) < 2.22044604925031e-16) ? (
       2467401100272.34*pow((*dxC), 3) + 14804406601634.0*pow((*dxC), 2)*(*xC) + 29608813203268.1*(*dxC)*pow((*xC), 2) + 98696.0440108936*(*dxC) + 19739208802178.7*pow((*xC), 3) + 197392.088021787*(*xC)
    )
    : (
       24674011002723.4*pow((*dxC), 3) + 64152428607080.8*pow((*dxC), 2)*(*xC) + 59217626406536.2*(*dxC)*pow((*xC), 2) + 197392.088021787*(*dxC) + 19739208802178.7*pow((*xC), 3) + 197392.088021787*(*xC)
    ))));
    };
    void PHSCORE::jacGlnl_update(){
    };
    void PHSCORE::jacGnlnl_update(){
    _jacGnlnl(0, 0) = 48000.0 + 1.0*(*Rnl)*(0.5*(*dxL) + (*xL))*(0.5*(*dxL) + 1.0*(*xL))/(*L) + 0.5*(*Rnl)*(0.25*pow((*dxL), 2) + 1.0*(*dxL)*(*xL) + 1.0*pow((*xL), 2) + 1.0)/(*L);
    _jacGnlnl(0, 1) = 1.0*(((*dxC) < -2.22044604925031e-16) ? (
       0.75*(*Cnl)*pow((*dxC), 2)/(*C) + 2.0*(*Cnl)*(*dxC)*(*xC)/(*C) + 1.5*(*Cnl)*pow((*xC), 2)/(*C) + 0.5/(*C)
    )
    : (((*dxC) < 2.22044604925031e-16) ? (
       0
    )
    : (
       0.75*(*Cnl)*pow((*dxC), 2)/(*C) + 2.0*(*Cnl)*(*dxC)*(*xC)/(*C) + 1.5*(*Cnl)*pow((*xC), 2)/(*C) + 0.5/(*C)
    )));
    _jacGnlnl(1, 1) = -(((*dxC) < -2.22044604925031e-16) ? (
       0.75*(*Cnl)*pow((*dxC), 2)/(*C) + 2.0*(*Cnl)*(*dxC)*(*xC)/(*C) + 1.5*(*Cnl)*pow((*xC), 2)/(*C) + 0.5/(*C)
    )
    : (((*dxC) < 2.22044604925031e-16) ? (
       0
    )
    : (
       0.75*(*Cnl)*pow((*dxC), 2)/(*C) + 2.0*(*Cnl)*(*dxC)*(*xC)/(*C) + 1.5*(*Cnl)*pow((*xC), 2)/(*C) + 0.5/(*C)
    )))*(((*dxC) < -2.22044604925031e-16) ? (
       1.25*(*Cnl)*pow((*dxC), 3)/(*C) + 3.25*(*Cnl)*pow((*dxC), 2)*(*xC)/(*C) + 3.0*(*Cnl)*(*dxC)*pow((*xC), 2)/(*C) + 1.0*(*Cnl)*pow((*xC), 3)/(*C) + 1.0*(*dxC)/(*C) + 1.0*(*xC)/(*C)
    )
    : (((*dxC) < 2.22044604925031e-16) ? (
       0.125*(*Cnl)*pow((*dxC), 3)/(*C) + 0.75*(*Cnl)*pow((*dxC), 2)*(*xC)/(*C) + 1.5*(*Cnl)*(*dxC)*pow((*xC), 2)/(*C) + 1.0*(*Cnl)*pow((*xC), 3)/(*C) + 0.5*(*dxC)/(*C) + 1.0*(*xC)/(*C)
    )
    : (
       1.25*(*Cnl)*pow((*dxC), 3)/(*C) + 3.25*(*Cnl)*pow((*dxC), 2)*(*xC)/(*C) + 3.0*(*Cnl)*(*dxC)*pow((*xC), 2)/(*C) + 1.0*(*Cnl)*pow((*xC), 3)/(*C) + 1.0*(*dxC)/(*C) + 1.0*(*xC)/(*C)
    ))) - (((*dxC) < -2.22044604925031e-16) ? (
       3.75*(*Cnl)*pow((*dxC), 2)/(*C) + 6.5*(*Cnl)*(*dxC)*(*xC)/(*C) + 3.0*(*Cnl)*pow((*xC), 2)/(*C) + 1.0/(*C)
    )
    : (((*dxC) < 2.22044604925031e-16) ? (
       0.375*(*Cnl)*pow((*dxC), 2)/(*C) + 1.5*(*Cnl)*(*dxC)*(*xC)/(*C) + 1.5*(*Cnl)*pow((*xC), 2)/(*C) + 0.5/(*C)
    )
    : (
       3.75*(*Cnl)*pow((*dxC), 2)/(*C) + 6.5*(*Cnl)*(*dxC)*(*xC)/(*C) + 3.0*(*Cnl)*pow((*xC), 2)/(*C) + 1.0/(*C)
    )))*(((*dxC) < -2.22044604925031e-16) ? (
       0.25*(*Cnl)*pow((*dxC), 3)/(*C) + 1.0*(*Cnl)*pow((*dxC), 2)*(*xC)/(*C) + 1.5*(*Cnl)*(*dxC)*pow((*xC), 2)/(*C) + 1.0*(*Cnl)*pow((*xC), 3)/(*C) + 0.5*(*dxC)/(*C) + 1.0*(*xC)/(*C)
    )
    : (((*dxC) < 2.22044604925031e-16) ? (
       1.0*(*Cnl)*pow((*xC), 3)/(*C) + 1.0*(*xC)/(*C)
    )
    : (
       0.25*(*Cnl)*pow((*dxC), 3)/(*C) + 1.0*(*Cnl)*pow((*dxC), 2)*(*xC)/(*C) + 1.5*(*Cnl)*(*dxC)*pow((*xC), 2)/(*C) + 1.0*(*Cnl)*pow((*xC), 3)/(*C) + 0.5*(*dxC)/(*C) + 1.0*(*xC)/(*C)
    ))) + 48000.0;
    };
    void PHSCORE::dxH_update(){
    _dxH(0, 0) = 1.0*(1.0*(*dxL) + 2.0*(*xL));
    _dxH(1, 0) = (((*dxC) < -2.22044604925031e-16) ? (
       4934802200544.68*pow((*dxC), 3) + 19739208802178.7*pow((*dxC), 2)*(*xC) + 29608813203268.1*(*dxC)*pow((*xC), 2) + 98696.0440108936*(*dxC) + 19739208802178.7*pow((*xC), 3) + 197392.088021787*(*xC)
    )
    : (((*dxC) < 2.22044604925031e-16) ? (
       19739208802178.7*pow((*xC), 3) + 197392.088021787*(*xC)
    )
    : (
       4934802200544.68*pow((*dxC), 3) + 19739208802178.7*pow((*dxC), 2)*(*xC) + 29608813203268.1*(*dxC)*pow((*xC), 2) + 98696.0440108936*(*dxC) + 19739208802178.7*pow((*xC), 3) + 197392.088021787*(*xC)
    )));
    };
    void PHSCORE::z_update(){
    };
    void PHSCORE::y_update(){
    _y(0, 0) = 1.0*(1.0*(*dxL) + 2.0*(*xL));
    };
    
    // Oprations Results Updates
    
    void PHSCORE::ud_x_update(){
        _ud_x = (x()) + (dx());
    };
    void PHSCORE::ijacFll_update(){
        _ijacFll = jacFll();
    };
    void PHSCORE::ud_vl_update(){
        _ud_vl = jacFll();
    };
    void PHSCORE::save_Fnl_update(){
        _save_Fnl = Fnl();
    };
    void PHSCORE::res_Fnl_update(){
        _res_Fnl = sqrt((Fnl()).dot(Fnl()));
    };
    void PHSCORE::Fnl_update(){
        _Fnl = Gnl();
    };
    void PHSCORE::jacFnl_update(){
        _jacFnl = jacGnlnl();
    };
    void PHSCORE::ijacFnl_update(){
        _ijacFnl = (jacFnl()).inverse();
    };
    void PHSCORE::ud_vnl_update(){
        _ud_vnl = (vnl()) + ((-1.0)*((ijacFnl())*(Fnl())));
    };
    void PHSCORE::step_Fnl_update(){
        _step_Fnl = sqrt(((Fnl()) + ((-1.0)*(save_Fnl()))).dot((Fnl()) + ((-1.0)*(save_Fnl()))));
    };
    
    // Initialization
    
    void PHSCORE::init(){
        
        
        // Functions Results Initialisation Data
        double jacFll_data[] = {};
        double jacFnll_data[] = {};
        double Gl_data[] = {};
        double Gnl_data[] = {0, 0};
        double jacGlnl_data[] = {};
        double jacGnlnl_data[] = {0, -0.5/(*L), 0, 0};
        double dxH_data[] = {0, 0};
        double z_data[] = {};
        double y_data[] = {0};
        
        // Oprations Results Initialisation Data
        double ud_x_data[] = {0.0, 0.0};
        double ijacFll_data[] = {};
        double ud_vl_data[] = {};
        double save_Fnl_data[] = {0.0, -0.0};
        double res_Fnl_data = 0.;
        double Fnl_data[] = {0.0, -0.0};
        double jacFnl_data[] = {48100.0, -1.0, 0.0, 48000.0};
        double ijacFnl_data[] = {2.079002079e-05, 4.33125433125e-10, 0.0, 2.08333333333e-05};
        double ud_vnl_data[] = {0.0, 0.0};
        double step_Fnl_data = 0.;    
        
        // Functions Results Initialisation
        
        _jacFll = Map<Matrix<double, 0, 0>> (jacFll_data);
        _jacFnll = Map<Matrix<double, 2, 0>> (jacFnll_data);
        _Gl = Map<Matrix<double, 0, 0>> (Gl_data);
        _Gnl = Map<Matrix<double, 2, 1>> (Gnl_data);
        _jacGlnl = Map<Matrix<double, 0, 2>> (jacGlnl_data);
        _jacGnlnl = Map<Matrix<double, 2, 2>> (jacGnlnl_data);
        _dxH = Map<Matrix<double, 2, 1>> (dxH_data);
        _z = Map<Matrix<double, 0, 0>> (z_data);
        _y = Map<Matrix<double, 1, 1>> (y_data);
        
        // Operations Results Initialisation
        
        _ud_x = Map<Matrix<double, 2, 1>> (ud_x_data);
        _ijacFll = Map<Matrix<double, 0, 0>> (ijacFll_data);
        _ud_vl = Map<Matrix<double, 0, 0>> (ud_vl_data);
        _save_Fnl = Map<Matrix<double, 2, 1>> (save_Fnl_data);
        _res_Fnl = res_Fnl_data;
        _Fnl = Map<Matrix<double, 2, 1>> (Fnl_data);
        _jacFnl = Map<Matrix<double, 2, 2>> (jacFnl_data);
        _ijacFnl = Map<Matrix<double, 2, 2>> (ijacFnl_data);
        _ud_vnl = Map<Matrix<double, 2, 1>> (ud_vnl_data);
        _step_Fnl = step_Fnl_data;
    };