def count_salary_categories(accounts: pd.DataFrame) -> pd.DataFrame:
    categories = ['Low Salary', 'Average Salary', 'High Salary']
    
    
    def get_category(income):
        if income < 20000:
            return 'Low Salary'
        elif income <= 50000:
            return 'Average Salary'
        else:
            return 'High Salary'
    
    accounts['category'] = accounts['income'].apply(get_category)
    counts = accounts['category'].value_counts().reindex(categories, fill_value=0)
    
    return pd.DataFrame({'category': counts.index, 'accounts_count': counts.values})