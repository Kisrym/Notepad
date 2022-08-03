from PyQt5 import uic, QtWidgets

class notepad(QtWidgets.QMainWindow):
    def __init__(self):
        super(notepad, self).__init__()
        uic.loadUi(r"janelas\notepad.ui", self)
    
        self.actionSalvar.triggered.connect(self.salvar)
        self.actionAbrir.triggered.connect(self.abrir)
        
    def salvar(self):
        fname = QtWidgets.QFileDialog.getSaveFileName(self, "Salvar Arquivo", "", "Documentos de Texto (*.txt)")

        if fname[0] != "":
            with open(fname[0], "w") as f:
                f.write(self.texto.toPlainText())
            
    def abrir(self):
        fname = QtWidgets.QFileDialog.getOpenFileName(self, "Abrir Arquivo", "", "Documentos de Texto (*.txt)")
        
        if fname[0] != "":
            with open(fname[0], "r") as f:
                self.texto.setText(f.read())

app = QtWidgets.QApplication([])

notepad_window = notepad()

notepad_window.show()
app.exec()