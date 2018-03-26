/*
 * Copyright (c) 2018 The Foundation for Research on Information Technologies in Society (IT'IS).
 * 
 * This file is part of iSEG
 * (see https://github.com/ITISFoundation/osparc-iseg).
 * 
 * This software is released under the MIT License.
 *  https://opensource.org/licenses/MIT
 */
#ifndef RTSTRUCTIMPORTER_MARCH09
#define RTSTRUCTIMPORTER_MARCH09

#include "config.h"

#include <qpushbutton.h>
#include <q3hbox.h>
#include <q3vbox.h>
#include <qwidget.h>
#include <qspinbox.h>
#include <qcheckbox.h>
#include <qlineedit.h>
#include <qlayout.h> 
#include <qlabel.h>
#include <qdialog.h>
#include <qcombobox.h>

#include <vector>

#include "SlicesHandler.h"

#include "../GDCM/vtkMyGDCMPolyDataReader.h"

class RtstructImport : public QDialog
{
	Q_OBJECT
public:
	RtstructImport(QString filename, SlicesHandler *hand3D, QWidget *parent=0, const char *name=0, Qt::WindowFlags wFlags=0);
	~RtstructImport();

private:
	SlicesHandler *handler3D;
	Q3HBox *hbox1;
	Q3HBox *hbox2;
	Q3HBox *hbox3;
	Q3HBox *hbox4;
	Q3VBox *vbox1;
	QSpinBox *sb_priority;
	QComboBox *cb_solids;
	QComboBox *cb_names;
	QLineEdit *le_name;
	QLabel *lb_priority;
	QLabel *lb_namele;
	QLabel *lb_namecb;
	QCheckBox *cb_new;
	QCheckBox *cb_ignore;
	QPushButton *pb_cancel;
	QPushButton *pb_ok;
	gdcmvtk_rtstruct::tissuevec tissues;
	std::vector<bool> vecnew;
	std::vector<bool> vecignore;
	std::vector<tissues_size_t> vectissuenrs;
	std::vector<int> vecpriorities;
	std::vector<std::string> vectissuenames;
	void storeparams();
	void updatevisibility();
	int currentitem;

signals:
//	void rtstruct_loaded();
	void begin_datachange(common::DataSelection &dataSelection, QWidget *sender = NULL, bool beginUndo = true);
	void end_datachange(QWidget *sender = NULL, common::EndUndoAction undoAction = common::EndUndo);

private slots:
	void solid_changed(int);
	void new_changed();
	void ignore_changed();
	void ok_pressed();
	void show_priorityInfo();
};

#endif
