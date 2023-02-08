#~/usr/bin/env python
"""
The main script for running experiments
"""
from data import get_dataset
import numpy as np
import pandas as pd
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split 
from sklearn import metrics 
from sklearn.tree import plot_tree
import matplotlib.pyplot as plt


def main():
    dataset_directory = 'data'
    dataset = 'spam' #volcanoes #voting #spam
    main.schema_spam, main.X_spam, main.y_spam = get_dataset(dataset, dataset_directory)
    
    dataset = 'voting' #volcanoes #voting #spam
    main.schema_voting, main.X_voting, main.y_voting = get_dataset(dataset, dataset_directory)
    
    dataset = 'volcanoes' #volcanoes #voting #spam
    main.schema_volcanoes, main.X_volcanoes, main.y_volcanoes = get_dataset(dataset, dataset_directory)

    
def _1_1_a():
    print('\n\n')
    
    #My Student ID last 4 digits are 0529, omitted the 0
    X_train_spam, X_test_spam, y_train_spam, y_test_spam = train_test_split(main.X_spam, main.y_spam, test_size=0.2, random_state=529)  
    X_train_voting, X_test_voting, y_train_voting, y_test_voting = train_test_split(main.X_voting, main.y_voting, test_size=0.2, random_state=529)
    X_train_volcanoes, X_test_volcanoes, y_train_volcanoes, y_test_volcanoes = train_test_split(main.X_volcanoes, main.y_volcanoes, test_size=0.2, random_state=529)
    
    # Create Decision Tree classifer object
    clf = DecisionTreeClassifier(criterion='entropy')
    
    # Train Decision Tree Classifer for Spam
    clf_spam = clf.fit(X_train_spam,y_train_spam)

         # Prediction accuracy Spam
    y_predict_spam = clf_spam.predict(X_test_spam)
    
        # Spam Model Accuracy, Height and Number of Leaves
    print("Spam Classifier - Accuracy:", metrics.accuracy_score(y_test_spam, y_predict_spam))
    print("Spam Classifier - Height:", clf_spam.get_depth())
    print("Spam Classifier - Number of Leaves:", clf_spam.get_n_leaves())
    
    print('\n\n')
    
    # Train Decision Tree Classifer for Voting
    clf_voting = clf.fit(X_train_voting,y_train_voting)

         # Prediction accuracy Voting
    y_predict_voting = clf_voting.predict(X_test_voting)
    
        # Voting Model Accuracy, Height and Number of Leaves
    print("Voting Classifier - Accuracy:", metrics.accuracy_score(y_test_voting, y_predict_voting))
    print("Voting Classifier - Height:", clf_voting.get_depth())
    print("Voting Classifier - Number of Leaves:", clf_voting.get_n_leaves())
    
    print('\n\n')
    
    #Train Decision Tree Classifer for Volcanoes
    clf_volcanoes = clf.fit(X_train_volcanoes,y_train_volcanoes)

        # Prediction accuracy Volcanoes
    y_predict_volcanoes = clf_volcanoes.predict(X_test_volcanoes)

        #Volcanoes Model Accuracy, Height and Number of Leaves
    print("Volcanoes Classifier - Accuracy:", metrics.accuracy_score(y_test_volcanoes, y_predict_volcanoes))
    print("Volcanoes Classifier - Height:", clf_volcanoes.get_depth())
    print("Volcanoes Classifier - Number of Leaves:", clf_volcanoes.get_n_leaves())
    

    
    #plt.figure(figsize=(10,8), dpi=150)
    #plot_tree(clf, feature_names=X_train_voting, filled=True);
    
    
def _1_1_b():
    
    X_train_voting, X_test_voting, y_train_voting, y_test_voting = train_test_split(main.X_voting, main.y_voting, test_size=0.2, random_state=529)
    
    # Create Decision Tree classifer object
    clf = DecisionTreeClassifier(criterion='gini')
    
    # Train Decision Tree Classifer for Voting
    clf_voting = clf.fit(X_train_voting,y_train_voting)

         # Prediction accuracy Voting
    y_predict_voting = clf_voting.predict(X_test_voting)
    
    print("Voting Classifier - Accuracy:", metrics.accuracy_score(y_test_voting, y_predict_voting))
    
    
    # Get the feature importances
    importances = clf.feature_importances_

    # Get the index of the feature with the highest importance
    highest_feature_index = importances.argmax()

    # Print the name of the feature with the highest importance
    print("Feature with highest gini value:", highest_feature_index)
    
    
    
def _1_1_c():
    X_train_spam, X_test_spam, y_train_spam, y_test_spam = train_test_split(main.X_spam, main.y_spam, test_size=0.2, random_state=529) 

    accuracies = []

    for depth in range(1, 51):
        clf = DecisionTreeClassifier(criterion='entropy', max_depth=depth)
        clf.fit(X_train_spam, y_train_spam)
        y_predict_spam = clf.predict(X_test_spam)
        acc = metrics.accuracy_score(y_test_spam, y_predict_spam)
        accuracies.append(acc)

    # Plot the accuracy vs. depth
    plt.plot(range(1, 51), accuracies)
    plt.xlabel('Depth of the Tree')
    plt.ylabel('Accuracy')
    plt.show()
    
def _1_2_():
    pass
    
   
    
if __name__ == "__main__":
    main()
    #_1_1_a()
    #_1_1_b()
    #_1_1_c()
    _1_2_()

