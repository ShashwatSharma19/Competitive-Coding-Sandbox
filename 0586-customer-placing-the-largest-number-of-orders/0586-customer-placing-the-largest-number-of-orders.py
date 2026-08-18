import pandas as pd

def largest_orders(orders: pd.DataFrame) -> pd.DataFrame:
    return pd.DataFrame({'customer_number': [orders['customer_number'].value_counts().idxmax()]})