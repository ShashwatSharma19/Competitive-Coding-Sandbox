import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    unique_salaries = employee['salary'].drop_duplicates()
    
    sorted_salaries = unique_salaries.sort_values(ascending=False)
    
    if len(sorted_salaries) < 2:
        return pd.DataFrame({'SecondHighestSalary': [None]})
    
    
    second_highest = sorted_salaries.iloc[1]
    
    return pd.DataFrame({'SecondHighestSalary': [second_highest]})