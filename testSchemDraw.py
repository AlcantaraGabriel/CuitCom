# -*- coding: cp1252 -*-
import SchemDraw as schem
import SchemDraw.elements as e
import SchemDraw.logic as l

d = schem.Drawing()
#   * = Nó
# --- = linha horizontal com comprimento padrão(3.0)
#  -- = linha horizontal com comprimento modificado
#  ||| = linha vertical com comprimento padrão(3.0)
#   || = linha vertical com comprimento modificado


#A*||
d.add(e.DOT,toplabel ='$A$',xy = [0.0 , 0.0])#A*
d.add(e.LINE,l = 9.0,d = 'down',xy = [0.0 , 0.0])#||

#*--NOT||*
d.add(e.DOT,xy= [0.0,-1.0]) #*
d.add(e.LINE,l = 0.8,d = 'right',xy = [0.0,-1.0])#--
d.add(l.NOT,d = 'down' , xy = [0.8 , -1.0])#NOT
d.add(e.LINE,l = 6.645,d = 'down',xy = [0.8,-2.35])#||
d.add(e.DOT,d = 'down',xy = [0.8 , -4.35])#*

#--AND--S2
d.add(e.LINE,l = 3.0 ,d = 'right',xy = [0.8,-4.35])#
d.add(l.AND2,d = 'right' , xy = [3.6 , -4.6])#AND
d.add(e.LINE,l = 1.55,d = 'right',xy = [5.45,-4.6],rgtlabel ='$S2$')#---S1



#*--AND--S3
d.add(e.DOT,d = 'down',xy = [0.8 , -6.05])#*
d.add(e.LINE,l = 3.0 ,d = 'right',xy = [0.8,-6.05])#--
d.add(l.AND2,d = 'right' , xy = [3.6 , -6.30])#AND
d.add(e.LINE,l = 1.55,d = 'right',xy = [5.45,-6.30],rgtlabel ='$S3$')#---S1


#B*||
d.add(e.DOT,toplabel ='$B$',xy = [2.0 , 0.0])#B*
d.add(e.LINE,l = 9.0,d = 'down',xy = [2.0 , 0.0])#||

#*--NOT||
d.add(e.DOT,xy= [2.0,-1.0]) #*
d.add(e.LINE,l = 0.8,d = 'right',xy = [2.0,-1.0])#--
d.add(l.NOT,d = 'down' , xy = [2.8 , -1.0])#NOT
d.add(e.LINE,l = 6.645,d = 'down',xy = [2.8,-2.35])#||

#*--
d.add(e.LINE,l = 0.8,d = 'right',xy = [2.8 , -4.85])#--
d.add(e.DOT,d = 'down',xy = [2.8 , -4.85])#*

#*--
d.add(e.LINE,l = 1.8,d = 'right',xy = [2 , -6.55])#--
d.add(e.DOT,d = 'down',xy = [2 , -6.55])#*



#*---S1
d.add(e.DOT,d = 'right',xy = [0.0 , -3.0])#*
d.add(e.LINE,l = 7.0,d = 'right',xy = [0.0,-3.0],rgtlabel ='$S1$')#---S1



#G1 = d.add(l.NOT,d = 'down' ,anchor='in1')

#no1 = d.add(e.DOT,xy= [A.here[0],A.here[1]])

#B = d.add(e.DOT,toplabel ='$B$',xy = [A.here[0]+3,A.here[1]])


#S = d.add(e.LINE, rgtlabel='$S$')
#A = d.add(e.DOT, xy=S.here)
#d.add(e.LINE, d='up', l=d.unit*1, ilabel='$A$')
d.draw()
